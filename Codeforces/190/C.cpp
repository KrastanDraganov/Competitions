// Div 1

#include <iostream>
#include <vector>

#define ednl '\n'

using namespace std;

const int MAXN = 1e5 + 3;

vector<int> graph[MAXN];
int subtree_size[MAXN];

char decomposition[MAXN];
bool is_centroid[MAXN];

void calc_subtree_sizes(int currv, int parent) {
    subtree_size[currv] = 1;

    for (int nextv : graph[currv]) {
        if (nextv == parent or is_centroid[nextv]) {
            continue;
        }

        calc_subtree_sizes(nextv, currv);
        subtree_size[currv] += subtree_size[nextv];
    }
}

int find_centroid(int currv, int parent, int all_vertices) {
    for (int nextv : graph[currv]) {
        if (nextv == parent or is_centroid[nextv]) {
            continue;
        }

        if (subtree_size[nextv] > (all_vertices / 2)) {
            return find_centroid(nextv, currv, all_vertices);
        }
    }

    return currv;
} 

void find_decomposition(int currv, char officer_rank) {
    calc_subtree_sizes(currv, -1);

    int curr_centroid = find_centroid(currv, -1, subtree_size[currv]);
    
    is_centroid[curr_centroid] = true;
    decomposition[curr_centroid] = officer_rank;

    for (int nextv : graph[curr_centroid]) {
        if (!is_centroid[nextv]) {
            find_decomposition(nextv, officer_rank + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int from, to;
        cin >> from >> to;

        --from;
        --to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    } 

    find_decomposition(0, 'A');

    for (int i = 0; i < n; ++i) {
        cout << decomposition[i] << " ";
    }
    cout << endl;
    
return 0;
}