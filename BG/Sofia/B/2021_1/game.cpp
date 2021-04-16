#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

#define endl '\n'
#define GCD 1
#define MAX 2

using namespace std;

vector<int> calc_log(int n) {
    vector<int> res(n + 3, 0);
    for (int i = 2; i <= n; ++i) {
        res[i] = res[i / 2] + 1;
    }

    return res;
}

template<int operation, typename T>
T get_value(T &x, T &y){
    if (operation == GCD) {
        return __gcd(x, y);
    }

    if (operation == MAX) {
        return max(x, y);
    }

    return -1;
}

template<int operation, typename T>
vector<vector<T>> calc_sparse_table(vector<T>& nums) {
    int n = (int) nums.size();

    vector<vector<T>> res(n, vector<T>(log2(n) + 1, 0));
    for (int i = 0; i < n; ++i) {
        res[i][0] = nums[i];
    }

    for (int range = 1; (1 << range) <= n; ++range) {
        for (int i = 0; i + (1 << range) - 1 < n; ++i) {
            res[i][range] = get_value<operation>(res[i][range - 1], res[i + (1 << (range - 1))][range - 1]);
        }
    }

    return res;
}

template<int operation, typename T>
T query(int l, int r, vector<vector<T>>& sparse_table, vector<int>& log) {
    if (l > r) {
        return 0;
    }

    int range = log[r - l + 1];
    return get_value<operation, T>(sparse_table[l][range], sparse_table[r - (1 << range) + 1][range]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> log = calc_log(n);
    vector<vector<long long>> gcd = calc_sparse_table<GCD>(nums);

    int l = 0;
    long long curr_gcd = 0;
    vector<int> interval_size(n, 0), interval_end(n, -1);

    for (int r = 0; r < n; ++r) {
        curr_gcd = __gcd(curr_gcd, nums[r]);
        
        while (l < r and curr_gcd < k) {
            interval_end[l] = (interval_size[r - 1] == 0 ? (l - 1) : (r - 1));
            ++l;
            curr_gcd = query<GCD>(l, r, gcd, log);
        }

        if (curr_gcd >= k) {
            interval_size[r] = r - l + 1;
        }
    }

    while (l < n) {
        interval_end[l] = (interval_size[n - 1] == 0 ? (l - 1) : (n - 1));
        ++l;
    }

    vector<vector<int>> rmq_interval = calc_sparse_table<MAX>(interval_size);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;

        int res = (interval_end[l] >= r ? r : interval_end[l]) - l + 1;
        res = max(res, query<MAX>(interval_end[l] + 1, r, rmq_interval, log));

        cout << res << endl;
    }
return 0;
}