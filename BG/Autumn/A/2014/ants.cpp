// O points - not finished code

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

struct Node {
    int64_t sum;
    int64_t lazy;
    int l, r;
    int counter;
};

const int MAXN = 1e5 + 3;
const int MAXLOG = 17;

int available_node_ind;
Node nodes[4 * MAXN + 4 * MAXLOG * MAXLOG];
int root[4 * MAXN + 4 * MAXLOG * MAXLOG];
int ants[MAXN];

int update_tree(int curr_node_ind, int curr_l, int curr_r, int query_l, int query_r, int new_value) {
    if (curr_l > query_r or curr_r < query_l or curr_l > curr_r) {
        return curr_node_ind;
    }

    if (curr_l == query_l and curr_r == query_r) {
        int new_node_ind = available_node_ind++;
        
        nodes[new_node_ind] = nodes[curr_node_ind];

        nodes[new_node_ind].lazy += new_value;
        nodes[new_node_ind].sum += new_value * nodes[new_node_ind].counter;
        
        return new_node_ind;
    }

    int mid = (curr_l + curr_r) / 2;
    
    nodes[curr_node_ind].l = update_tree(nodes[curr_node_ind].l, curr_l, mid, query_l, min(mid, query_r), new_value);
    nodes[curr_node_ind].r = update_tree(nodes[curr_node_ind].r, mid + 1, curr_r, max(mid + 1, query_l), query_r, new_value);

    return curr_node_ind;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, n;
    cin >> q >> n;

    for (int i = 0; i < n; ++i) {
        cin >> ants[i];
    }

    available_node_ind = 0;
    build_tree(1, 1, 0, n - 1);

    int s = 0;
    for (int city = 2; city <= q + 1; ++city) {
        int p, x, y, v, z, t;
        cin >> p >> x >> y >> v >> z >> t;

        int l = (x + s) % q + 1;
        int r = (y + s) % q + 1;

        int i = (z + s) % q + 1;
        int j = (t + s) % q + 1;

        update_tree(city, l, r, v);
        s = query_tree(city, l, r, i, j);

        cout << s << endl;
    }

return 0;
}