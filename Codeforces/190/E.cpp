#include <iostream>

#define endl '\n'

using namespace std;

const int MAXN = 4e3 + 3;
const int MAXK = 803;
const int INF = 1e9;

int dp[MAXN][MAXK];
int prefix_sum[MAXN][MAXN], unfamiliarity[MAXN][MAXN];

void calc_dp(int gondolas, int l, int r, int optimal_l, int optimal_r) {
    int mid = (l + r) / 2;
    
    dp[mid][gondolas] = INF;
    int curr_optimal_ind = optimal_l;

    for (int i = optimal_l; i <= optimal_r; ++i) {
        if (dp[mid][gondolas] > dp[i - 1][gondolas - 1] + unfamiliarity[i][mid]) {
            dp[mid][gondolas] = dp[i - 1][gondolas - 1] + unfamiliarity[i][mid];
            curr_optimal_ind = i;
        }
    }

    if (l <= mid - 1) {
        calc_dp(gondolas, l, mid - 1, optimal_l, curr_optimal_ind);
    }

    if (mid + 1 <= r) {
        calc_dp(gondolas, mid + 1, r, curr_optimal_ind, optimal_r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char value;
            cin >> value;

            prefix_sum[i][j] = (value - '0') - prefix_sum[i - 1][j - 1]
                             + prefix_sum[i - 1][j] + prefix_sum[i][j - 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            unfamiliarity[i][j] = (prefix_sum[j][j] + prefix_sum[i - 1][i - 1]
                                - prefix_sum[i - 1][j] - prefix_sum[j][i - 1]) / 2;
        }
    }

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = INF;
    }

    for (int i = 1; i <= k; ++i) {
        calc_dp(i, 1, n, 1, n);
    }

    cout << dp[n][k] << endl;
return 0;
}