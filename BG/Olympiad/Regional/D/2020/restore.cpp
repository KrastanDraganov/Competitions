#include <iostream>

#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 3, MAXL = 17;
int fenwick[MAXN], res[MAXN];

void update_tree(int ind, int val) {
    while (ind < MAXN) {
        fenwick[ind] += val;
        ind += (ind & (-ind));
    }
}

int find_kth(int target) {
    int pos = 0;
    for (int i = MAXL - 1; i >= 0; --i) {
        int new_pos = pos | (1 << i);
        if (target - fenwick[new_pos] > 0) {
            pos = new_pos;
            target -= fenwick[new_pos];
        }
    }

    return pos + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int num = 1; num <= n; ++num) {
        update_tree(num, 1);
    }

    for (int i = 0; i < n; ++i) {
        int counter;
        cin >> counter;

        int target = n - i - counter;
        int curr_num = find_kth(target);

        res[i] = curr_num;
        update_tree(curr_num, -1);
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
return 0;
}