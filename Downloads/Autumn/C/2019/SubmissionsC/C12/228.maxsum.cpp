#include <bits/stdc++.h>
using namespace std;

int decomp[100000];
int decompr[100000];
int n, k;
short row[100000];
int nums[1000];
int ans;
int maxr[100000];

void decomposition() {
    decomp[0] = row[0];
    decompr[n - 1] = row[n - 1];
    for (int i = 1; i < n; ++ i) {
        for (int j = 0; j < k; ++ j) {
            if (i - nums[j] >= 0) {
                decomp[i] = max(decomp[i], decomp[i - nums[j]] + row[i]);
            }
            const int ind = n - i - 1;
            if (ind + nums[j] <= n - 1) {
                decompr[ind] = max(decompr[ind], decompr[ind + nums[j]] + row[ind]);
                maxr[ind] = max(maxr[ind + 1], decompr[ind]);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++ i) {
        cin >> row[i];
    }
    for (int i = 0; i < k; ++ i) {
        cin >> nums[i];
    }
    decomposition();
    for (int i = 0; i < n; ++ i) {
        ans = max(ans, decomp[i] + maxr[i]);
    }
    cout << ans << endl;
    return 0;
}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2
*/