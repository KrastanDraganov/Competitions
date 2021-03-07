#include<iostream>
#include<vector>
#include<string>
#include<array>

#define endl '\n'

using namespace std;

const int MAXN = 33, INF = 1e9 + 3;
const int MAX_CELLS = 2 * MAXN * MAXN;
const array<int, 2> dirs[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

struct Edge {
    int to, flow, capacity, reversed_ind;

    Edge (int _to, int _capacity, int _reversed_ind) {
        to = _to;
        flow = 0;
        capacity = _capacity;
        reversed_ind = _reversed_ind;
    }
};

bool is_cat[MAXN][MAXN];
vector<Edge> graph[MAX_CELLS];
int visited[MAX_CELLS];

void add_edge(int from, int to, int capacity) {
    graph[from].push_back(Edge(to, capacity, (int) graph[to].size()));
    graph[to].push_back(Edge(from, 0, (int) graph[from].size() - 1));
}

int dfs(int currv, int min_capacity, int sink) {
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

    int n, m = -1;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;

        if(m == -1){
            m = (int) row.size();
        }

        for (int j = 0; j < m; ++j) {
            is_cat[i][j] = (row[j] == '1');
        }
    }

    int duplicate = n * m;
    int source = 2 * duplicate;
    int sink = source + 1;

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            int currv = x * m + y;
            add_edge(currv, duplicate + currv, 1);
            
            if (is_cat[x][y]) {
                add_edge(source, currv, 1);
            }
            if (x == 0 or x == n - 1 or y == 0 or y == m - 1) {
                add_edge(duplicate + currv, sink, 1);
            }

            for (int i = 0; i < 4; ++i) {
                int newx = x + dirs[i][0];
                int newy = y + dirs[i][1];

                if (newx < 0 or newx >= n or newy < 0 or newy >= m) {
                    continue;
                }
                
                int nextv = newx * m + newy;
                add_edge(duplicate + currv, nextv, 1);   
            }
        }
    }
    
    int curr_flow = 0, max_flow = 0;
    do {
        for (int i = 0; i < MAX_CELLS; ++i) {
            visited[i] = false;
        }
        curr_flow = dfs(source, INF, sink);
        max_flow += curr_flow;
    } while (curr_flow > 0);

    cout << max_flow << endl;
return 0;
}