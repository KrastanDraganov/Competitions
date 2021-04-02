#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 3;
long long nums[MAXN];
int precompute[MAXN];

long long calc_gcd(int l, int r) {
    long long res = 0;
    for (int i = l; i <= r; ++i) {
        res = __gcd(res, nums[i]);
    }

    return res;
}

int slow_query(int l, int r, int n, long long k) {
    int i = l, res = 0;
    long long curr_gcd = 0;

    precompute[0] = 0;
    for (int i = 1; i < n; ++i) {
        precompute[i] = -1;
    }

    for (int j = l; j <= r; ++j) {
        curr_gcd = __gcd(curr_gcd, nums[j]);
        
        while (i < j and j <= r and curr_gcd < k) {
            ++i;
            while (i < j and __gcd(nums[i], nums[j]) < k) {
                ++i;
                ++j;
            }

            curr_gcd = calc_gcd(i, j);
        }

        if (curr_gcd >= k) {
            res = max(res, j - i + 1);
        }

        precompute[j] = res;
    }

    for (int i = 1; i < n; ++i) {
        if (precompute[i] == -1) {
            precompute[i] = precompute[i - 1];
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int q;
    cin >> q;

    slow_query(0, n - 1, n, k);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        // cout << slow_query(l - 1, r - 1, n, k) << endl;
        cout << precompute[r - 1] << endl;
    }
return 0;
}