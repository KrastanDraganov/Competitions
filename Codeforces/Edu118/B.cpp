#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 1; i <= (n / 2); ++i) {
        cout << nums[i] << " " << nums[0] << endl;
    }
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

