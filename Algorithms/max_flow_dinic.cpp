#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN = 5e3 + 3, INF = 1e9 + 3;

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
    while (is_augmenting_path(source, sink, n)) {
        for (int i = 0; i < n; ++i) {
            edge_ind[i] = 0;
        }

        int curr_flow = 0;
        do {
            curr_flow = dfs(source, INF, sink);
            max_flow += 1ll * curr_flow;
        } while (curr_flow > 0);
    }

    cout << max_flow << endl;
return 0;
}