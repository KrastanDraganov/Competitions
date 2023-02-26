#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t num;
    vector<int64_t> pancakes;

    while (cin >> num)
    {
        pancakes.push_back(num);
    }

    int n = (int) pancakes.size();

    int64_t max_sum = pancakes[0];
    int res_l = 0, res_r = 0;

    int64_t curr_sum = pancakes[0];
    int start_l = 0;

    if (curr_sum < 0)
    {
        curr_sum = 0;
        start_l = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        curr_sum += pancakes[i];

        if (curr_sum > max_sum or (max_sum == curr_sum and (i - start_l + 1) > (res_r - res_l + 1)))
        {
            max_sum = curr_sum;
            res_l = start_l;
            res_r = i;
        }

        if (curr_sum < 0)
        {
            curr_sum = 0;
            start_l = i + 1;
        }
    }

    cout << max_sum << " " << res_l << " " << res_r << endl;

    return 0;
}