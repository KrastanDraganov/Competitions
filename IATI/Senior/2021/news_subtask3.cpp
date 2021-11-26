#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 3;
vector<int> graph[MAXN];
bool is_informed[MAXN];

int euler_tour[2 * MAXN];
int in_time[MAXN], out_time[MAXN];

int tree[4 * 2 * MAXN];
bool lazy[4 * 2 * MAXN];

void dfs(int currv, int parent, int& timer) {
    euler_tour[timer] = is_informed[currv];
    in_time[currv] = timer++;

    for (int nextv : graph[currv]) {
        if (nextv != parent) {
            dfs(nextv, currv, timer);
        }
    }

    euler_tour[timer] = is_informed[currv];
    out_time[currv] = timer++;
}

void update_tree_value(int ind, int tl, int tr) {
    int interval_size = tr - tl + 1;
    tree[ind] = interval_size;
    lazy[ind] = true;
}

void push_lazy(int ind, int tl, int tr) {
    if (tl == tr or !lazy[ind]) {
        return;
    }

    int mid = (tl + tr) / 2;

    update_tree_value(2 * ind, tl, mid);
    update_tree_value(2 * ind + 1, mid + 1, tr);

    lazy[ind] = false;
}

void build_tree(int ind, int tl, int tr) {
    if (tl == tr) {
        tree[ind] = euler_tour[tl];
        return;
    }

    int mid = (tl + tr) / 2;
    build_tree(2 * ind, tl, mid);
    build_tree(2 * ind + 1, mid + 1, tr);

    tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
}

void update_tree(int ind, int tl, int tr, int l, int r) {
    if (l > r or l > tr or r < tl or tl > tr) {
        return;
    }

    if (tl == l and tr == r) {
        update_tree_value(ind, tl, tr);
        return;
    }

    push_lazy(ind, tl, tr);

    int mid = (tl + tr) / 2;
    update_tree(2 * ind, tl, mid, l, min(mid, r));
    update_tree(2 * ind + 1, mid + 1, tr, max(l, mid + 1), r);

    tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
}

int query_tree(int ind, int tl, int tr, int l, int r) {
    if (l > r or l > tr or r < tl or tl > tr) {
        return 0;
    }
    
    if (tl == l and tr == r) {
        return tree[ind];
    }

    push_lazy(ind, tl, tr);

    int mid = (tl + tr) / 2;
    return query_tree(2 * ind, tl, mid, l, min(mid, r))
         + query_tree(2 * ind + 1, mid + 1, tr, max(l, mid + 1), r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }

    for (int i = 0; i < n; ++i) {
        cin >> is_informed[i];
    }

    int timer = 0;
    int euler_tour_size = 2 * n;

    dfs(0, -1, timer);

    build_tree(1, 0, euler_tour_size - 1);

    int q;
    cin >> q;

    for (int query = 0; query < q; ++query) {
        int type, x, k;
        cin >> type >> x >> k;
        --x;

        int query_l = in_time[x];
        int query_r = out_time[x];

        if (type == 1) {
            update_tree(1, 0, euler_tour_size - 1, query_l, query_r);
        } else {
            cout << query_tree(1, 0, euler_tour_size - 1, query_l, query_r) / 2 << endl;
        }
    }
return 0;
}