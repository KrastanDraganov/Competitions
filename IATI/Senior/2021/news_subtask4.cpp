#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 3;

struct NodeData {
    vector<pair<int, int>> values;
    unordered_map<int, int> fenwick;

    NodeData() {
        values.clear();
        fenwick.clear();
    }

    NodeData(pair<int, int> value) {
        values = {value};
        fenwick.clear();
    }

    void add_tree(int pos, int val) {
        while (pos < 2 * MAXN) {
            fenwick[pos] += val;
            pos += (pos & (-pos));
        }
    }

    int sum_tree(int pos) {
        int res = 0;
        while (pos > 0) {
            res += fenwick[pos];
            pos -= (pos & (-pos));
        }

        return res;
    }

    void build_fenwick() {
        for (int i = 0; i < (int) values.size(); ++i) {
            if (values[i].second == 1) {
                add_tree(i + 1, 1);
            }
        }
    }

    int find_pos(int target) {
        return upper_bound(values.begin(), values.end(), make_pair(target, 3)) - values.begin() - 1;
    }
};

vector<int> graph[MAXN];
bool is_informed[MAXN];
int depth[MAXN];

pair<int, int> euler_tour[2 * MAXN];
int in_time[MAXN], out_time[MAXN];

NodeData tree[4 * 2 * MAXN];

void dfs(int currv, int parent, int& timer) {
    if (parent == -1) {
        depth[currv] = 0;
    } else {
        depth[currv] = depth[parent] + 1;
    }

    euler_tour[timer] = {depth[currv], is_informed[currv]};
    in_time[currv] = timer++;

    for (int nextv : graph[currv]) {
        if (nextv != parent) {
            dfs(nextv, currv, timer);
        }
    }

    euler_tour[timer] = {depth[currv], is_informed[currv]};
    out_time[currv] = timer++;
}

void merge_arrays(vector<pair<int, int>>& result, vector<pair<int, int>>& nums1, vector<pair<int, int>>& nums2) {
    int n = (int) nums1.size();
    int m = (int) nums2.size();

    result.resize(n + m);

    int i = 0, j = 0, k = 0;
    while (i < n and j < m) {
        if (nums1[i] < nums2[j]) {
            result[k++] = nums1[i++];
        } else {
            result[k++] = nums2[j++];
        }
    }

    while (i < n) {
        result[k++] = nums1[i++];
    }
    while (j < m) {
        result[k++] = nums2[j++];
    }
}

void build_tree(int ind, int tl, int tr) {
    if (tl == tr) {
        tree[ind] = NodeData(euler_tour[tl]);
        tree[ind].build_fenwick();
        return;
    }

    int mid = (tl + tr) / 2;
    build_tree(2 * ind, tl, mid);
    build_tree(2 * ind + 1, mid + 1, tr);

    merge_arrays(tree[ind].values, tree[2 * ind].values, tree[2 * ind + 1].values);
    tree[ind].build_fenwick();
}

int query_tree(int ind, int tl, int tr, int l, int r, int depth_limit) {
    if (l > r or l > tr or r < tl or tl > tr) {
        return 0;
    }
    
    if (tl == l and tr == r) {
        int target = tree[ind].find_pos(depth_limit);
        return (target == -1) ? 0 : tree[ind].sum_tree(target + 1); 
    }

    int mid = (tl + tr) / 2;
    return query_tree(2 * ind, tl, mid, l, min(mid, r), depth_limit)
         + query_tree(2 * ind + 1, mid + 1, tr, max(l, mid + 1), r, depth_limit);
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

        int depth_limit = k + depth[x];

        cout << query_tree(1, 0, euler_tour_size - 1, query_l, query_r, depth_limit) / 2 << endl;
    }
return 0;
}