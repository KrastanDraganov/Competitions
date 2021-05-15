#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

void update_tree(int ind, int64_t val, vector<int64_t>& tree, int n) {
    while (ind <= n) {
        tree[ind] += val;
        ind += (ind & (-ind));
    }
}

int64_t query_tree(int ind, vector<int64_t>& tree) {
    int64_t res = 0;
    while (ind > 0) {
        res += tree[ind];
        ind -= (ind & (-ind));
    }

    return res;
}

void update_range(int l, int r, int val, vector<vector<int64_t>>& fenwick, int n) {
    update_tree(l, val, fenwick[0], n);
    update_tree(r + 1, -val, fenwick[0], n);

    update_tree(l, val * (l - 1), fenwick[1], n);
    update_tree(r + 1, -val * r, fenwick[1], n);
}

int64_t prefix_sum(int pos, vector<vector<int64_t>>& fenwick) {
    return query_tree(pos, fenwick[0]) * pos - query_tree(pos, fenwick[1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a, b, mod;
    cin >> a >> b >> mod;

    int last = 1;
    vector<vector<int64_t>> fenwick(2, vector<int64_t>(n + 3, 0));
    
    update_range(1, 1, last, fenwick, n);
    for (int i = 2; i <= n; ++i) {
        last = (last * a + b) % mod;
        update_range(i, i, last, fenwick, n);
    }

    int q;
    cin >> q;
    
    int64_t res = 0;
    for (int i = 0; i < q; ++i) {
        int l = (last * a + b) % n;
        int r = (l * a + b) % n;
        last = r;

        if (l > r) {
            swap(l, r);
        }
        ++l;
        ++r;

        if (i % 2 == 0) {
            res += (prefix_sum(r, fenwick) - prefix_sum(l - 1, fenwick));
            continue;
        }

        int new_val = (last * a + b) % mod;
        last = new_val;

        update_range(l, r, new_val, fenwick, n);
    }

    cout << res << endl;
return 0;
}