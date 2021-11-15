#include <iostream>
#include <queue>
#include <climits>
#include <utility>

#define endl '\n'

using namespace std;

const int MAXN = 853;
int nums[MAXN], prefix_sum[MAXN];
int dp[MAXN][MAXN];
bool used[MAXN];

int brute_force(int score, int left_nums_counter, int n, int k) {
    if (left_nums_counter < k) {
        return score;
    }

    int res = INT_MIN;
    
    queue<pair<int, int>> left_nums;
    int curr_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }

        left_nums.push({nums[i], i});
        curr_sum += nums[i];
        used[i] = true;

        if ((int) left_nums.size() < k) {
            continue;
        }

        used[left_nums.front().second] = false;
        curr_sum -= left_nums.front().first;

        int new_score = score + (curr_sum - nums[i])
                      - left_nums.front().first * nums[i];

        used[i] = false;
        res = max(res, brute_force(new_score, left_nums_counter - k + 2, n, k));

        used[i] = true;
        left_nums.pop();
    }

    while (!left_nums.empty()) {
        used[left_nums.front().second] = false;
        left_nums.pop();
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << brute_force(0, n, n, k) << endl;

    // for (int i = 0; i < n; ++i) {
    //     prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    // }

    // for (int interval_size = 0; interval_size < n; ++interval_size) {
    //     for (int l = 0; l < n; ++l) {
    //         int r = l + interval_size - 1;

    //         if (r - l + 1 < k) {
    //             dp[l][r] = 0;
    //             continue;
    //         }

    //         for (int target1 = 0; target1 <= k - 2; ++target1) {
    //             int target2 = k - 2 - target1;

    //             dp[l][r] = max(dp[l][r], - );
    //         }
    //     }
    // }

    // cout << dp[0][n - 1] << endl;
return 0;
}