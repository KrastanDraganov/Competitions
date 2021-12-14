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

    // dp[i][0] - number of complete subsequences (from 0 to x) with mex i
    // dp[i][1] - number of incomplete subsequences (from 0 to x - 2 and x and x - 2 etc) with mex i
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        int curr = nums[i];

        add_mod(dp[curr + 1][0], dp[curr + 1][0]);
        add_mod(dp[curr + 1][0], dp[curr][0]);

        add_mod(dp[curr + 1][1], dp[curr + 1][1]);
        if (curr - 1 >= 0) {
            add_mod(dp[curr - 1][1], dp[curr - 1][1]);
            add_mod(dp[curr - 1][1], dp[curr - 1][0]);
        }
    }

    int res = 0;
    for (int i = 0; i <= n + 1; ++i) {
        for (int type = 0; type < 2; ++type) {
            add_mod(res, dp[i][type]);
        }
    }
    add_mod(res, -1 + MOD);

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