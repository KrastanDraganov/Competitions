#include<iostream>
#include<vector>

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
bool visited[MAXN];

void add_edge (int from, int to, int capacity) {
    graph[from].push_back(Edge(to, capacity, (int) graph[to].size()));
    graph[to].push_back(Edge(from, 0, (int) graph[from].size() - 1));
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
        int from, to, capacity;
        cin >> from >> to >>capacity;
        add_edge(from, to, capacity);
    }

    int source, sink;
    cin >> source >> sink;
    
    long long max_flow = 0;
    int curr_flow = 0;

    do {
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }
        curr_flow = dfs(source, INF, sink);
        max_flow += 1ll * curr_flow;
    } while (curr_flow > 0);

    cout << max_flow << endl;
return 0;
}