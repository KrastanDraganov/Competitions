#include <iostream>
#include <vector>
#include <unordered_map>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN = 1e5 + 3;
 
vector<int> graph[MAXN];
int64_t colors[MAXN], subtree_size[MAXN];
 
unordered_map<int, int> counter[MAXN];
int64_t result[MAXN], max_color[MAXN];
 
void dfs(int currv, int parent) {
    int biggest_subtree = -1, target = -1;
    subtree_size[currv] = 1;
 
    for (int nextv : graph[currv]) {
        if (nextv == parent) {
            continue;
        }
 
        dfs(nextv, currv);
        subtree_size[currv] += subtree_size[nextv];
 
        if (biggest_subtree == -1 or biggest_subtree < subtree_size[nextv]) {
            biggest_subtree = subtree_size[nextv];
            target = nextv;
        }
    }
 
    if (target == -1) {
        counter[currv][colors[currv]] = 1;
        max_color[currv] = 1;
        result[currv] = colors[currv];
        return;
    }
 
    counter[currv] = move(counter[target]);
    max_color[currv] = max_color[target];
    result[currv] = result[target];
 
    ++counter[currv][colors[currv]];
 
    if (counter[currv][colors[currv]] > max_color[currv]) {
        max_color[currv] = counter[currv][colors[currv]];
        result[currv] = colors[currv];
    } else if (counter[currv][colors[currv]] == max_color[currv]) {
        result[currv] += colors[currv];
    }
 
    for (int nextv : graph[currv]) {
        if (nextv == parent or nextv == target) {
            continue;
        }
 
        for (auto &mp : counter[nextv]) {
            counter[currv][mp.first] += mp.second;
 
            if (counter[currv][mp.first] > max_color[currv]) {
                result[currv] = mp.first;
                max_color[currv] = counter[currv][mp.first];
            } else if (counter[currv][mp.first] == max_color[currv]) {
                result[currv] += mp.first;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }
 
    for (int i = 1; i < n; ++i) {
        int from, to;
        cin >> from >> to;
 
        --from;
        --to;
 
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
 
    dfs(0, -1);
 
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
 
    return 0;
}