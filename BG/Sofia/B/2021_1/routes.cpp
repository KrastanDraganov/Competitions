#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 3;
vector<int> graph[MAXN];
int subtree_dist[MAXN], all_dist[MAXN];
bool visited[MAXN];

void dfs1(int currv) {
    visited[currv] = true;

    int& res = subtree_dist[currv];
    res = 1;
    for (int nextv : graph[currv]) {
        if (!visited[nextv]) {
            dfs1(nextv);
            res = max(res, subtree_dist[nextv] + 1);
        }
    }
}

void dfs2(int currv, int parent, int prev_max_dist) {
    all_dist[currv] = max(subtree_dist[currv], prev_max_dist + 1);
    visited[currv] = true;

    int max_dist1 = 0, max_dist2 = 0;
    for (int nextv : graph[currv]) {
        if (nextv == parent) {
            continue;
        }

        if (subtree_dist[nextv] > max_dist1) {
            max_dist2 = max_dist1;
            max_dist1 = subtree_dist[nextv];
        } else if(subtree_dist[nextv] > max_dist2) {
            max_dist2 = subtree_dist[nextv];
        }
    }

    for (int nextv : graph[currv]) {
        if (visited[nextv]) {
            continue;
        }

        int next_max_dist = prev_max_dist + 1;
        if (subtree_dist[nextv] == max_dist1) {
            next_max_dist = max(next_max_dist, max_dist2 + 1);
        } else {
            next_max_dist = max(next_max_dist, max_dist1 + 1);
        }

        dfs2(nextv, currv, next_max_dist);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        if(!visited[i]) {
            dfs2(i, -1, 0);
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int target;
        cin >> target;
        cout << all_dist[target - 1] << " ";
    }
    cout << endl;
return 0;
}