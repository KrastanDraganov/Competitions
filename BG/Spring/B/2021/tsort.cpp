#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define endl '\n'

using namespace std;

void compress_array(int n, vector<int>& nums) {
    vector<pair<int, int>> helper;
    for (int i = 0; i < n; ++i) {
        helper.push_back({nums[i], i});
    }

    sort(helper.begin(), helper.end());

    for (int i = 0; i < n; ++i) {
        nums[helper[i].second] = i;
    }
}

// Lazy O(NlogN) instead of O(N)
int get_middle_element(int n, vector<int> nums) {
    sort(nums.begin(), nums.begin() + n);
    return nums[n / 2];
}

void shift_array(int pos, vector<int>& nums, vector<int>& swaps) {
    int target = nums[pos];
    for (int i = pos; i > 0; --i) {
        nums[i] = nums[i - 1];
    }

    nums[0] = target;
    swaps.push_back(pos + 1);
}

void swap_halves(int n, vector<int>& nums, vector<int>& swaps) {
    for (int i = 0; i < n / 2; ++i) {
        shift_array(n - 1, nums, swaps);
    }
}

void sort_array(int n, vector<int>& nums, vector<int>& swaps) {
    if (n == 2) {
        if (nums[0] > nums[1]) {
            swaps.push_back(2);
        }

        return;
    }

    int divider = get_middle_element(n, nums);

    int wrong_first_half = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (nums[i] >= divider) {
            ++wrong_first_half;
        }
    }

    int last_first_half = n / 2 - 1;
    while (wrong_first_half > 0) {
        if (nums[last_first_half] < divider) {
            shift_array(last_first_half, nums, swaps);
            continue;
        }

        if (nums[n - 1] < divider) {
            --wrong_first_half;
        }

        shift_array(n - 1, nums, swaps);
    }

    sort_array(n / 2, nums, swaps);

    swap_halves(n, nums, swaps);
    sort_array(n / 2, nums, swaps);
    swap_halves(n, nums, swaps);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    compress_array(n, nums);

    vector<int> swaps;
    sort_array(n, nums, swaps);

    cout << (int) swaps.size() << endl;
    for (int curr : swaps) {
        cout << curr << " ";
    }
    cout << endl;
return 0;
}