#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<iomanip>

#define endl '\n'

using namespace std;

const int MAXN = 1e3 + 3, INF = 1e9 + 3;

struct Edge {
    int to, flow, capacity, reversed_ind;

    Edge (int _to, int _capacity, int _reversed_ind) {
        to = _to;
        flow = 0;
        capacity = _capacity;
        reversed_ind = _reversed_ind;
    }
};

int sheep[MAXN][2], barns[MAXN][2];
int needed_time[MAXN][MAXN];

vector<Edge> graph[MAXN];
int dist[MAXN], edge_ind[MAXN];

void add_edge(int from, int to, int capacity) {
    graph[from].push_back(Edge(to, capacity, (int) graph[to].size()));
    graph[to].push_back(Edge(from, 0, (int) graph[from].size() - 1));
}

bool is_augmenting_path(int source, int sink, int n) {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
    }
    dist[source] = 0;

    queue<int> bfs;
    bfs.push(source);

    while (!bfs.empty()) {
        int currv = bfs.front();
        bfs.pop();

        if (currv == sink) {
            return true;
        }

        for (Edge edge : graph[currv]) {
            if (dist[edge.to] != -1 or (edge.capacity - edge.flow == 0)) {
                continue;
            }

            dist[edge.to] = dist[currv] + 1;
            bfs.push(edge.to);
        }
    }

    return false;
}

int dfs(int currv, int min_capacity, int sink) {
    if (currv == sink) {
        return min_capacity;
    }

    for (int& i = edge_ind[currv]; i < (int) graph[currv].size(); ++i) {
        Edge& edge = graph[currv][i];

        int left_capacity = edge.capacity - edge.flow;
        if (left_capacity == 0 or (dist[currv] + 1 != dist[edge.to])) {
            continue;
        }
        
        int next_capacity = min(min_capacity, left_capacity);
        int curr_flow = dfs(edge.to, next_capacity, sink);

        if (curr_flow == 0) {
            continue;
        }

        edge.flow += curr_flow;

        Edge& reversed_edge = graph[edge.to][edge.reversed_ind];
        reversed_edge.flow -= curr_flow;

        return curr_flow;
    }

    return 0;
}

int find_max_flow(int source, int sink, int n) {
    int res = 0;
    while (is_augmenting_path(source, sink, n)) {
        for (int i = 0; i < n; ++i) {
            edge_ind[i] = 0;
        }

        int curr_flow = 0;
        do {
            curr_flow = dfs(source, INF, sink);
            res += curr_flow;
        } while (curr_flow > 0);
    }

    return res;
}

bool is_matching(int limit, int n, int m, int k) {
    int source = n + m;
    int sink = source + 1;
    int all_vertices = sink + 1;

    for (int i = 0; i < all_vertices; ++i) {
        graph[i].clear();
    }

    for (int i = 0; i < n; ++i) {
        add_edge(source, i, 1);
    }
    for (int i = 0; i < m; ++i) {
        add_edge(n + i, sink, k);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (needed_time[i][j] <= limit) {
                add_edge(i, n + j, 1);
            }
        }
    }

    int max_flow = find_max_flow(source, sink, all_vertices);
    return max_flow == n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> sheep[i][0] >> sheep[i][1];
    }
    for (int i = 0; i < m; ++i) {
        cin >> barns[i][0] >> barns[i][1];
    }

    int max_time = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int diff_x = sheep[i][0] - barns[j][0];
            int diff_y = sheep[i][1] - barns[j][1];
            needed_time[i][j] = diff_x * diff_x + diff_y * diff_y;
            max_time = max(max_time, needed_time[i][j]);
        }
    }
    
    int l = 0, r = max_time;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (is_matching(mid, n, m, k)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << fixed << setprecision(6) << sqrt(r + 1) << endl;
return 0;
}