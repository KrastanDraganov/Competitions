#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        pos[num - 1] = i;
    }

    int curr_pos = 0;
    int64_t res = 0;

    for (int i = 0; i < min(k, n); ++i) {
        int target_num = i % n;

        int keys_tried = pos[target_num] - curr_pos;
        if (curr_pos > pos[target_num]) {
            keys_tried += n;
        }

        res += 1ll * keys_tried;

        curr_pos = pos[target_num];
    }

    if (k > n) {
        vector<int64_t> prefix_sum(n + 1);

        for (int target_num = 0; target_num < n; ++target_num) {
            int keys_tried = pos[target_num] - curr_pos;

            if (curr_pos > pos[target_num]) {
                keys_tried += n;
            }

            prefix_sum[target_num + 1] = prefix_sum[target_num] + 1ll * keys_tried;

            curr_pos = pos[target_num];
        }

        k -= n;
        res += 1ll * (k / n) * prefix_sum[n];
        res += prefix_sum[k % n];
    }

    cout << res << endl;
return 0;
}