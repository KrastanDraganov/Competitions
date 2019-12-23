#include <bits/stdc++.h>
using namespace std;

long long decomp[100000];
long long decompr[100000];
long long n, k;
short row[100000];
long long nums[1000];
long long ans;
long long maxr[100000];

void decomposition() {
    decomp[0] = row[0];
    decompr[n - 1] = row[n - 1];
    for (long long i = 1; i < n; ++ i) {
        for (long long j = 0; j < k; ++ j) {
            if (i - nums[j] >= 0) {
                decomp[i] = max(decomp[i], decomp[i - nums[j]] + row[i]);
            }
            const long long ind = n - i - 1;
            if (ind + nums[j] <= n - 1) {
                decompr[ind] = max(decompr[ind], decompr[ind + nums[j]] + row[ind]);
                maxr[ind] = max(maxr[ind + 1], decompr[ind]);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    for (long long i = 0; i < n; ++ i) {
        cin >> row[i];
    }
    for (long long i = 0; i < k; ++ i) {
        cin >> nums[i];
    }
    decomposition();
    for (long long i = 0; i < n; ++ i) {
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