#include <iostream>
#include <string>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string target, s;
    cin >> target >> s;

    int n = (int) target.size();
    int m = (int) s.size();

    string helper = target + "#" + s;
    int k = (int) helper.size();

    vector<int> z(n + m + 1, 0);
    int l = 0, r = 0;

    for (int i = 1; i < k; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i + z[i] < k and helper[z[i]] == helper[i + z[i]]) {
            ++z[i];
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    int res = 0;
    for (int i = 0; i < m; ++i) {
        if (z[i + n + 1] == n) {
            ++res;
        }
    }

    cout << res << endl;
return 0;
}
