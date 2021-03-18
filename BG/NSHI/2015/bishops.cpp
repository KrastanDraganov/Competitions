#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN = 1e3 + 3, INF = 1e9 + 3;
const int MAX_VERTICES = 12 * MAXN;

struct Edge {
    int to, flow, capacity, reversed_ind;

    Edge (int _to, int _capacity, int _reversed_ind) {
        to = _to;
        flow = 0;
        capacity = _capacity;
        reversed_ind = _reversed_ind;
    }
};

bool is_blocked[MAXN][MAXN];
int right_diagonal_id[MAXN][MAXN], left_diagonal_id[MAXN][MAXN];

vector<Edge> graph[MAX_VERTICES];
int dist[MAX_VERTICES], edge_ind[MAX_VERTICES];

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

void advance_right_diagonal(int start_row, int start_col, int& counter, int source, int n) {
    bool added_to_source = false;
    for (int row = start_row, col = start_col; row < n and col < n; ++row, ++col) {
        if (is_blocked[row][col]) {
            ++counter;
            added_to_source = false;
            continue;
        }

        right_diagonal_id[row][col] = counter;
        if (!added_to_source) {
            add_edge(source, counter, 1);
            added_to_source = true;
        }
    }

    ++counter;
}

void assign_id_right_diagonal(int& counter, int source, int n) {
    int start_row = 0, start_col = 0;
    while (start_col < n) {
        advance_right_diagonal(start_row, start_col, counter, source, n);
        ++start_col;
    }

    start_row = 1, start_col = 0;
    while (start_row < n) {
        advance_right_diagonal(start_row, start_col, counter, source, n);
        ++start_row;
    }
}

void advance_left_diagonal(int start_row, int start_col, int& counter, int sink, int n) {
    bool added_to_sink = false;
    for (int row = start_row, col = start_col; row < n and col >= 0; ++row, --col) {
        if (is_blocked[row][col]) {
            ++counter;
            added_to_sink = false;
            continue;
        }

        left_diagonal_id[row][col] = counter;
        if (!added_to_sink) {
            add_edge(counter, sink, 1);
            added_to_sink = true;
        }
    }

    ++counter;
}

void assign_id_left_diagonal(int& counter, int sink, int n) {
    int start_row = 0, start_col = n - 1;
    while (start_col >= 0) {
        advance_left_diagonal(start_row, start_col, counter, sink, n);
        --start_col;
    }

    start_row = 0, start_col = n - 1;
    while (start_row < n) {
        advance_left_diagonal(start_row, start_col, counter, sink, n);
        ++start_row;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        int row, col;
        cin >> row >> col;
        is_blocked[row - 1][col - 1] = true; 
    }

    int source = 4 * (n + k);
    int sink = source + 1;
    int all_vertices = sink + 1;

    int counter = 0;
    assign_id_right_diagonal(counter, source, n);
    assign_id_left_diagonal(counter, sink, n);

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (is_blocked[row][col]) {
                continue;
            }

            add_edge(right_diagonal_id[row][col], left_diagonal_id[row][col], 1);
        }
    }
    
    int max_flow = 0;
    while (is_augmenting_path(source, sink, all_vertices)) {
        for (int i = 0; i < all_vertices; ++i) {
            edge_ind[i] = 0;
        }

        int curr_flow = 0;
        do {
            curr_flow = dfs(source, INF, sink);
            max_flow += curr_flow;
        } while (curr_flow > 0);
    }

    cout << max_flow << endl;
return 0;
}