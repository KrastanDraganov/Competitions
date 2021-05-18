#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int MAXN = (1 << 10) + 3;
int nums[MAXN][MAXN], fenwick[MAXN][MAXN];

void update_tree(int row, int col, int new_val) {
    for (int x = row; x < MAXN; x += (x & (-x))) {
        for (int y = col; y < MAXN; y += (y & (-y))) {
            fenwick[x][y] += new_val;
        }
    }
}

int prefix_sum(int row, int col) {
    int res = 0;
    for (int x = row; x > 0; x -= (x & (-x))) {
        for (int y = col; y > 0; y -= (y & (-y))) {
            res += fenwick[x][y];
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; ++test) {
        int n;
        cin >> n;

        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                fenwick[i][j] = nums[i][j] = 0;
            }
        }

        string type = "";
        while (cin >> type and type != "END") {
            if (type == "SET") {
                int x, y, new_val;
                cin >> x >> y >> new_val;

                update_tree(x + 1, y + 1, new_val - nums[x][y]);
                nums[x][y] = new_val;

                continue;
            }

            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            cout << prefix_sum(x2 + 1, y2 + 1) + prefix_sum(x1, y1)
                  - prefix_sum(x2 + 1, y1) - prefix_sum(x1, y2 + 1) << endl;
        }
    }

return 0;
}