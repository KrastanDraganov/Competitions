// Not solved - wrong answer

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int MOD = 998244353;

void add_mod(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // dp[i][0] - number of complete subsequences (from 1 to i)
    // dp[i][1] - number of incomplete subsequences (from 1 to i - 2 and i)
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        int curr = nums[i];

        add_mod(dp[curr][1], dp[curr][1]);
        if (curr == 0) {
            add_mod(dp[curr][1], 1);
        }
        if (curr >= 1) {
            add_mod(dp[curr][1], dp[curr - 1][1]);
        }

        add_mod(dp[curr][0], dp[curr][0]);
        if (curr == 1) {
            add_mod(dp[curr][0], 1);
        }
        if (curr >= 2) {
            add_mod(dp[curr][0], dp[curr - 2][1]);
        }
    }

    int res = 0;
    for (int i = 0; i <= n; ++i) {
        for (int type = 0; type < 2; ++type) {
            add_mod(res, dp[i][type]);
        }
    }

    cout << res << endl;
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


