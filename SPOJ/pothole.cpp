#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN = 203, INF = 1e9 + 3;

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

    int tests;
    cin>>tests;

    for (int test = 0; test < tests; ++test) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            graph[i].clear();
        }
        
        int source = 0, sink = n - 1;
        for (int from = 0; from < sink; ++from) {
            int m;
            cin >> m;

            for (int i = 0; i < m; ++i){
                int to;
                cin >> to;
                --to;

                int capacity = (from == source or to == sink) ? 1 : (n + 3);
                add_edge(from, to, capacity);
            }
        }

        int max_flow = 0, curr_flow = 0;
        do {
            for (int i = 0; i < n; ++i) {
                visited[i] = false;
            }
            curr_flow = dfs(source, INF, sink);
            max_flow += curr_flow;
        } while (curr_flow > 0);

        cout << max_flow << endl;
    }
return 0;
}