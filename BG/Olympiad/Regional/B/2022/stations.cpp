#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

struct Edge {
    int to, len;

    Edge() : to(-1), len(0) {}
    Edge(int _to, int _len) : to(_to), len(_len) {}
};

const int MAXN = 1e5 + 3;

vector<Edge> graph[MAXN];
int subtree_size[MAXN];
int64_t dp_down[MAXN], dp_all[MAXN];

void dfs1(int currv, int parent) {
    subtree_size[currv] = 1;
    dp_down[currv] = 0;

    for (Edge& nextv : graph[currv]) {
        if (nextv.to == parent) {
            continue;
        }

        dfs1(nextv.to, currv);

        subtree_size[currv] += subtree_size[nextv.to];
        dp_down[currv] += dp_down[nextv.to];
        dp_down[currv] += 1ll * nextv.len * subtree_size[nextv.to];
    }
}

void dfs2(int currv, int parent, int64_t dp_up, int up_nodes_counter) {
    dp_all[currv] = dp_down[currv] + dp_up;

    int right_nodes_counter = 0;
    for (Edge& nextv : graph[currv]) {
        if (nextv.to == parent) {
            continue;
        }

        right_nodes_counter += subtree_size[nextv.to];

        if (dp_up > 0) {
            dp_all[currv] += dp_up * subtree_size[nextv.to];
            dp_all[currv] += dp_down[nextv.to] * up_nodes_counter;
            dp_all[currv] += 1ll * nextv.len * subtree_size[nextv.to] * up_nodes_counter;
        }
    }

    int64_t right_dp_down = dp_down[currv];
    
    int left_nodes_counter = 0;
    int64_t left_dp_down = 0;

    for (Edge& nextv : graph[currv]) {
        if (nextv.to == parent) {
            continue;
        }

        right_dp_down -= 1ll * nextv.len * subtree_size[nextv.to];
        right_dp_down -= dp_down[nextv.to];

        right_nodes_counter -= subtree_size[nextv.to];

        int64_t new_dp_up = dp_up + 1ll * nextv.len * (up_nodes_counter + 1);
        int new_up_nodes_counter = up_nodes_counter + (subtree_size[currv] - subtree_size[nextv.to]);

        if (right_nodes_counter > 0) {
            dp_all[currv] += 1ll * subtree_size[nextv.to] * right_dp_down;
            dp_all[currv] += dp_down[nextv.to] * right_nodes_counter;
            dp_all[currv] += 1ll * nextv.len * right_nodes_counter * subtree_size[nextv.to];

            new_dp_up += right_dp_down;
            new_dp_up += 1ll * nextv.len * right_nodes_counter;
        }

        if (left_nodes_counter > 0) {
            new_dp_up += left_dp_down;
            new_dp_up += 1ll * nextv.len * left_nodes_counter;
        }

        dfs2(nextv.to, currv, new_dp_up, new_up_nodes_counter);

        left_dp_down += dp_down[nextv.to];
        left_dp_down += 1ll * nextv.len * subtree_size[nextv.to];

        left_nodes_counter += subtree_size[nextv.to];
    }
}

void slow_solution(int n) {
    cout << "slow:\n";
    for (int currv = 0; currv < n; ++currv) {
        dfs1(currv, -1);

        int64_t right_dp_down = dp_down[currv];
        int right_nodes_counter = n - 1;
        
        int64_t res = dp_down[currv];

        for (Edge& nextv : graph[currv]) {
            right_dp_down -= 1ll * nextv.len * subtree_size[nextv.to];
            right_dp_down -= dp_down[nextv.to];

            right_nodes_counter -= subtree_size[nextv.to];

            if (right_nodes_counter == 0) {
                break;
            }

            res += 1ll * subtree_size[nextv.to] * right_dp_down;
            res += dp_down[nextv.to] * right_nodes_counter;
            res += 1ll * nextv.len * right_nodes_counter * subtree_size[nextv.to];

        }

        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int from, to, len;
        cin >> from >> to >> len;

        --from;
        --to;

        graph[from].emplace_back(to, len);
        graph[to].emplace_back(from, len);
    }

    dfs1(0, -1);
    dfs2(0, -1, 0ll, 0);

    for (int i = 0; i < n; ++i) {
        cout << dp_all[i] << endl;
    }

return 0;
}