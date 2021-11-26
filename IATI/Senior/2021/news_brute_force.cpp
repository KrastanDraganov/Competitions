#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 3;
vector<int> graph[MAXN];
int parent[MAXN];
bool is_informed[MAXN];

void assign_parents(int currv, int prev) {
    parent[currv] = prev;

    for (int nextv : graph[currv]) {
        if (nextv != prev) {
            assign_parents(nextv, currv);
        }
    }
}

void spread_news(int currv, int curr_level, int level_limit) {
    is_informed[currv] = true;

    if (curr_level == level_limit) {
        return;
    }

    for (int nextv : graph[currv]) {
        if (nextv != parent[currv]) {
            spread_news(nextv, curr_level + 1, level_limit);
        }
    }
}

int count_informed(int currv, int curr_level, int level_limit) {
    int res = is_informed[currv];

    if (curr_level == level_limit) {
        return res;
    }

    for (int nextv : graph[currv]) {
        if (nextv != parent[currv]) {
            res += count_informed(nextv, curr_level + 1, level_limit);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }

    assign_parents(0, -1);

    for (int i = 0; i < n; ++i) {
        cin >> is_informed[i];
    }

    int q;
    cin >> q;

    for (int query = 0; query < q; ++query) {
        int type, x, k;
        cin >> type >> x >> k;
        --x;

        if (type == 1) {
            spread_news(x, 0, k);
        } else {
            cout << count_informed(x, 0, k) << endl;
        }
    }
return 0;
}