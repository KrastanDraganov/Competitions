#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 3, MAXM = 1e6 + 3;

vector<pair<int, int>> graph[MAXN];
int in_time[MAXN], min_time[MAXN], component[MAXN], comp_size[MAXN];
bool is_bridge[MAXM];

vector<int> tree[MAXN];
int dist_down[MAXN], all_dist[MAXN];

void find_bridges(int currv, int parent, int& timer) {
    in_time[currv] = min_time[currv] = timer++;

    for (auto [nextv, ind] : graph[currv]) {
        if (nextv == parent) {
            continue;
        }

        if (min_time[nextv] == 0) {
            find_bridges(nextv, currv, timer);
            
            if (min_time[nextv] > in_time[currv]) {
                is_bridge[ind] = true;
            }
        }

        min_time[currv] = min(min_time[currv], min_time[nextv]);
    }
}

void find_component(int currv, int id) {
    component[currv] = id;
    ++comp_size[id];

    for (auto [nextv, ind] : graph[currv]) {
        if (component[nextv] == -1 and !is_bridge[ind]) {
            find_component(nextv, id);
        }
    }
}

void build_tree(int n) {
    for (int currv = 0; currv < n; ++currv) {
        for (auto [nextv, ind] : graph[currv]) {
            if (is_bridge[ind]) {
                tree[component[currv]].push_back(component[nextv]);
            }
        }
    }
}

void dfs_down(int currv) {
    int& res = dist_down[currv];
    res = comp_size[currv];
    
    for (int nextv : tree[currv]) {
        if (dist_down[nextv] != 0) {
            continue;
        }
        
        dfs_down(nextv);
        res = max(res, dist_down[nextv] + comp_size[currv]);
    }
}

void dfs_up(int currv, int parent, int max_dist_up) {
    all_dist[currv] = max(dist_down[currv], max_dist_up + comp_size[currv]);

    int max_dist_down1 = 0, max_dist_down2 = 0;
    for (int nextv : tree[currv]) {
        if (nextv == parent) {
            continue;
        }

        if (dist_down[nextv] > max_dist_down1) {
            max_dist_down2 = max_dist_down1;
            max_dist_down1 = dist_down[nextv];
        } else if(dist_down[nextv] > max_dist_down2) {
            max_dist_down2 = dist_down[nextv];
        }
    }

    for (int nextv : tree[currv]) {
        if (all_dist[nextv] != 0) {
            continue;
        }

        int next_max_dist = max_dist_up;
        if (dist_down[nextv] == max_dist_down1) {
            next_max_dist = max(next_max_dist, max_dist_down2);
        } else {
            next_max_dist = max(next_max_dist, max_dist_down1);
        }
        next_max_dist += comp_size[currv];

        dfs_up(nextv, currv, next_max_dist);
    }
}

void find_max_dist_tree(int n) {
    for (int i = 0; i < n; ++i) {
        if (dist_down[i] == 0) {
            dfs_down(i);
            dfs_up(i, -1 , 0);
        }
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
        graph[from].push_back({to, i});
        graph[to].push_back({from, i});
    }

    int timer = 1;
    for (int i = 0; i < n; ++i) {
        if (min_time[i] == 0) {
            find_bridges(i, -1, timer);
        }
    }

    for (int i = 0; i < n; ++i) {
        component[i] = -1;
    }

    int all_components = 0;
    for (int i = 0; i < n; ++i) {
        if(component[i] == -1) {
            find_component(i, all_components++);
        }
    }

    build_tree(n);
    find_max_dist_tree(all_components);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int city;
        cin >> city;

        int target = component[city - 1];
        cout << all_dist[target] << " ";
    }
    cout << endl;
return 0;
}