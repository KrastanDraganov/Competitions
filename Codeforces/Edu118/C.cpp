#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

bool check(int64_t k, int n, int64_t h, vector<int64_t>& hits) {
    for (int i = 0; i < n - 1; ++i) {
        h -= min(k, hits[i + 1] - hits[i]);
    }
    h -= k;

    return h <= 0;
}

void solve() {
    int n;
    int64_t h;
    cin >> n >> h;

    vector<int64_t> hits(n);
    for (int i = 0; i < n; ++i) {
        cin >> hits[i];
    }

    int64_t l = 0, r = h;
    while (l <= r) {
        int64_t mid = (l + r) / 2;

        if (check(mid, n, h, hits)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << r + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; ++test) {
        solve();
    }
return 0;
}


