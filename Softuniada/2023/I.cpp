#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

vector<int> remove_lis(vector<int>& nums)
{
    int n = (int) nums.size();

    vector<int> lis_num;
    vector<int> lis_index;
    vector<int> path(n, -1);

    for (int i = 0; i < n; ++i)
    {
        if (lis_num.empty() or nums[i] > lis_num.back())
        {
            path[i] = (lis_num.empty() ? -1 : lis_index.back());
            lis_num.push_back(nums[i]);
            lis_index.push_back(i);
        }
        else
        {
            int target = upper_bound(lis_num.begin(), lis_num.end(), nums[i]) - lis_num.begin();
            path[i] = ((target == 0) ? -1 : lis_index[target - 1]);
            lis_num[target] = nums[i];
            lis_index[target] = i;
        }
    }

    int current_index = lis_index.back();
    while (current_index != -1)
    {
        // cout << nums[current_index] << " ";
        nums[current_index] = -1;
        current_index = path[current_index];
    }

    vector<int> result;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] != -1)
        {
            result.push_back(nums[i]);
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // cout << "first lis: ";
    nums = remove_lis(nums);
    // cout << endl;
    
    // cout << "second lis: ";
    reverse(nums.begin(), nums.end());
    nums = remove_lis(nums);
    // cout << endl;

    cout << (int) nums.size() << endl;

    return 0;
}