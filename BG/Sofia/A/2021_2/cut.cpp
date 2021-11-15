#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

const int MAXN = 1e6 + 3;

struct Fenwick {
    vector<int> tree;

    Fenwick() {
        tree.resize(MAXN, 0);
    }

    void add(int pos, int value) {
        while (pos < MAXN) {
            tree[pos] += value;
            pos += (pos & (-pos));
        }
    }

    int sum(int pos) {
        int res = 0;
        while (pos > 0) {
            res += tree[pos];
            pos -= (pos & (-pos));
        }

        return res;
    }
};

vector<int> compress_heights(vector<int>& heights) {
    int n = (int) heights.size();
    
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = {heights[i], i};
    }

    sort(nums.begin(), nums.end());

    vector<int> res(n);
    int curr_num = 1;

    for (int i = 0; i < n; ++i) {
        if (i > 0 and nums[i].first != nums[i - 1].first) {
            ++curr_num;
        }

        res[nums[i].second] = curr_num;
    }

    return res;
}

long long brute_force(vector<int>& nums, int k) {
    int n = (int) nums.size();

    Fenwick fenwick;
    long long res = 0;

    for (int l = 0; l < n; ++l) {
        fenwick.add(nums[l], 1);

        for (int r = l + 1; r < n; ++r) {
            fenwick.add(nums[r], 1);

            if (r - l + 1 - fenwick.sum(max(nums[l], nums[r])) < k) {
                cout << l << " " << r << endl;
                ++res;
            }
        }

        fenwick.add(nums[l], -1);
        for (int r = l + 1; r < n; ++r) {
            fenwick.add(nums[r], -1);
        }
    }

    return res;
}

long long subproblem4(vector<int>& nums, int k) {
    int n = (int) nums.size();

    stack<pair<int, int>> prev_nums;
    prev_nums.push({nums[0], 1});

    long long res = 0;
    int left_in_stack = 1;

    for (int i = 1; i < n; ++i) {
        bool are_same = false;
        int new_counter = 1;
        int curr_counter = 0;

        cout << "for " << nums[i] << ": \n";
        while (!prev_nums.empty() and nums[i] >= prev_nums.top().first) {
            are_same = (nums[i] == prev_nums.top().first);
            curr_counter = prev_nums.top().second;
            
            cout << prev_nums.top().first << ", " << curr_counter << " -> ";

            prev_nums.pop();
            left_in_stack -= curr_counter;

            res += left_in_stack * curr_counter;
            new_counter += curr_counter;
            cout << res << endl;
        }

        if (prev_nums.empty()) {
            if (are_same) {
                new_counter = curr_counter + 1;
            } else {
                new_counter = 1;
            }
        }

        prev_nums.push({nums[i], new_counter});
        left_in_stack += new_counter;

        // if (are_same) {
        //     prev_nums.push({nums[i], counter + });
        //     left_in_stack += counter + 1;
        // } else {
        //     prev_nums.push({nums[i], 1});
        //     ++left_in_stack;
        // }

        // for every consecutive pair
        // ++res;
    }

    return res;
}

long long init(vector<int> heights, int k) {
    heights = compress_heights(heights);

    for (int height : heights) {
        cout << height << " ";
    }
    cout << endl;

    return subproblem4(heights, k);
}