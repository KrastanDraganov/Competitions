#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN = 203, MAX_NUM = 1e3 + 3, INF = 1e9 + 3;
const int MAX_VERTICES = 2 * MAXN;

struct Edge {
    int to, flow, capacity, reversed_ind;

    Edge (int _to, int _capacity, int _reversed_ind) {
        to = _to;
        flow = 0;
        capacity = _capacity;
        reversed_ind = _reversed_ind;
    }
};

vector<Edge> graph[MAX_VERTICES];
int nums[MAXN];
bool visited[MAX_VERTICES], is_prime[MAX_NUM];

void find_primes() {
    is_prime[0] = is_prime[1] = false;
    for (int num = 2; num < MAX_NUM; ++num) {
        is_prime[num] = true;
        for(int div = 2; div * div <= num; ++div) {
            is_prime[num] &= (num % div != 0);
        }
    }
}

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

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    find_primes();

    int source = 2 * n;
    int sink = source + 1;
    int all_vertices = 2 * n + 2;

    for (int i = 0; i < n; ++i) {
        add_edge(source, i, 1);
        add_edge(n + i, sink, 1);

        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }

            int sum = nums[i] + nums[j];
            if (is_prime[sum]) {
                add_edge(i, n + j, 1);
            }
        }
    }
    
    int curr_flow = 0, max_flow = 0;
    do {
        for (int i = 0; i < all_vertices; ++i) {
            visited[i] = false;
        }
        curr_flow = dfs(source, INF, sink);
        max_flow += curr_flow;
    } while (curr_flow > 0);

    cout << max_flow / 2 << endl;
return 0;
}