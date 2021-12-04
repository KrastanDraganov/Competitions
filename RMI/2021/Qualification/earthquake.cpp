#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define endl '\n'

using namespace std;

const long double EPS = 0.0001;

struct Edge {
    int from, to;
    int64_t cost, time;

    Edge () : from(-1), to(-1), cost(0), time(0) {}

    Edge(int _from, int _to, int64_t _cost, int64_t _time) {
        from = _from;
        to = _to;
        cost = _cost;
        time = _time;
    }

    bool operator<(const Edge& comp) {
        long double ratio1 = 1.0 * cost / time;
        long double ratio2 = 1.0 * comp.cost / comp.time;

        return ratio1 < ratio2;
    }
};

bool cmp1 (const Edge& edge1, const Edge& edge2) {
    if (edge1.cost == edge2.cost) {
        return edge1.time < edge2.time;
    }

    return edge1.cost < edge2.cost;
}

bool cmp2 (const Edge& edge1, const Edge& edge2) {
    long double ratio1 = 1.0 * edge1.cost / edge1.time;
    long double ratio2 = 1.0 * edge2.cost / edge2.time;

    return ratio1 > ratio2;
}

bool cmp3 (const Edge& edge1, const Edge& edge2) {
    if (edge1.cost == edge2.cost) {
        return edge1.time < edge2.time;
    }

    return edge1.cost < edge2.cost;
}

struct DSU {
    int all_nodes;
    vector<int> parent;
    vector<int> rank;

    DSU(int _all_nodes) {
        all_nodes = _all_nodes;
        
        parent.resize(all_nodes);
        for (int i = 0; i < all_nodes; ++i) {
            parent[i] = i;
        }

        rank.resize(all_nodes, 0);
    }

    int find_parent(int currv) {
        if (currv == parent[currv]) {
            return currv;
        }

        return parent[currv] = find_parent(parent[currv]);
    }

    bool union_nodes(int x, int y) {
        int root_x = find_parent(x);
        int root_y = find_parent(y);

        if (root_x == root_y) {
            return false;
        }

        if (rank[root_x] < rank[root_y]) {
            swap(root_x, root_y);
        }

        parent[root_y] = root_x;
        rank[root_x] += rank[root_y];

        return true;
    }
};

long double find_mst(int n, int m, int64_t cost_limit, vector<Edge>& edges, int cmp_ind) {
    switch(cmp_ind) {
        case 0:
            sort(edges.begin(), edges.end(), cmp1);
            break;

        case 1:
            sort(edges.begin(), edges.end(), cmp2);
            break;

        case 2:
            sort(edges.begin(), edges.end(), cmp3);
            break;   
    }

    DSU dsu = DSU(n);
    int64_t cost_to_build = 0;
    int64_t time_to_build = 0;

    for (int i = 0; i < m; ++i) {
        if (dsu.union_nodes(edges[i].from, edges[i].to)) {
            cost_to_build += edges[i].cost;
            time_to_build += edges[i].time;
        }
    }

    if (cost_to_build > cost_limit) {
        return 0;
    }
    
    return 1.0 * (cost_limit - cost_to_build) / time_to_build;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int64_t f;
    cin >> n >> m >> f;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int from, to, cost, time;
        cin >> from >> to >> cost >> time;
        edges[i] = Edge(from - 1, to - 1, cost, time);
    }

    long double res = 0.0;
    for (int i = 0; i < 3; ++i) {
        long double curr = find_mst(n, m, f, edges, i);

        if (curr > res) {
            res = curr;
        }
    }
    cout << fixed << setprecision(4) << res << endl;
return 0;
}