#include <iostream>
#include <vector>
#include <queue>
 
#define endl '\n'
 
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> nums(n);
    priority_queue<int> biggest;
    priority_queue<int> smallest;
 
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        biggest.push(nums[i]);
        smallest.push(-nums[i]);
    }
 
    int l = 0, r = n - 1;
    while (l < r)
    {
        int small = -smallest.top();
        int big = biggest.top();
 
        if (nums[l] == small)
        {
            ++l;
            smallest.pop();
        }
        else if (nums[l] == big)
        {
            ++l;
            biggest.pop();
        }
        else if (nums[r] == small)
        {
            --r;
            smallest.pop();
        }
        else if (nums[r] == big)
        {
            --r;
            biggest.pop();
        }
        else
        {
            cout << l + 1 << " " << r + 1 << endl;
            return;
        }
    }
 
    cout << -1 << endl;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tests;
    cin >> tests;
 
    while (tests--)
    {
        solve();
    }
 
    return 0;
}