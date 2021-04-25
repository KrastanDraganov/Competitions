#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

int calc_prefix_function(int start_value, int target, string& num, vector<int>& prefix) {
    int res = start_value;
    while (res > 0 and num[res] != num[target]) {
        res = prefix[res - 1];
    }

    if (num[res] == num[target]) {
        ++res;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num;
    cin >> num;

    int n = (int) num.size();
    vector<int> prefix(n, 0);
    vector<int> marked = prefix;

    int max_marked = 0, res_start_ind = 0;
    for (int i = 1; i < n; ++i) {
        prefix[i] = calc_prefix_function(prefix[i - 1], i, num, prefix);

        int limit = (i + 1) / 2;
        if (num[marked[i - 1]] == num[i] and marked[i - 1] + 1 <= limit) {
            marked[i] = marked[i - 1] + 1;
        } else if (marked[i - 1] > 0) {
            marked[i] = calc_prefix_function(prefix[marked[i - 1] - 1], i, num, prefix);
        } else {
            marked[i] = 0;
        }

        if (marked[i] > max_marked) {
            max_marked = marked[i];
            res_start_ind = i - marked[i] + 1;
        }
    }

    cout << max_marked << " " << res_start_ind + 1 << endl;
return 0;
}