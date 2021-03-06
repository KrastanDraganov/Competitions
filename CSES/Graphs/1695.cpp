#include<iostream>
#include<vector>
#include<array>

#define endl '\n'

using namespace std;

const int MAXN = 503, INF = 1e9 + 3;

struct Edge {
    int to, flow, capacity, reversed_ind;

    Edge (int _to, int _capacity, int _reversed_ind) {
        to = _to;
        flow = 0;
        capacity = _capacity;
        reversed_ind = _reversed_ind;
    }
};

vector<Edge> graph[MAXN];
int visited[MAXN];
bool is_edge[MAXN][MAXN];

void add_edge (int from, int to, int capacity) {
    is_edge[from][to] = is_edge[to][from] = true;
    graph[from].push_back(Edge(to, capacity, (int) graph[to].size()));
    graph[to].push_back(Edge(from, capacity, (int) graph[from].size() - 1));
}

int dfs (int currv, int min_capacity, int sink) {
    if (currv == sink) {
        return min_capacity;
    }

    visited[currv] = true;
    for (Edge& edge : graph[currv]) {
        int left_capacity = edge.capacity - edge.flow;
        
        if (visited[edge.to] or left_capacity == 0) {
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        add_edge(from - 1, to - 1, 1);
    }

    int source = 0, sink = n - 1;

    int curr_flow = 0;
    do {
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }
        curr_flow = dfs(source, INF, sink);
    } while (curr_flow > 0);

    vector<array<int, 2>> res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (is_edge[i][j] and visited[i] and !visited[j]) {
                res.push_back({i + 1, j + 1});
            }
        }
    }

    cout << (int) res.size() << endl;
    for (array<int, 2> curr : res) {
        cout << curr[0] << " " << curr[1] << endl;
    }
return 0;
}