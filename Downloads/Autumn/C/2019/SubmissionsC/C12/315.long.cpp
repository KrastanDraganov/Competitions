#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int countl[26];
int used[26];
int ans, countans;
char cans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    if (n == 0 || m == 0 || k == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int strings = 0; strings < n; ++ strings) {
        for (int i = 0; i < m; ++ i) {
            used[i] = false;
        }
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); ++ i) {
            if (used[s[i] - 97] == false){
                ++ countl[s[i] - 97];
                used[s[i] - 97] = true;
            }
        }
    }
    for (int i = 0; i < m; ++ i) {
        if (countl[i] == ans) { ++ countans; }
        if (countl[i] > ans) { cans = i + 97; ans = countl[i]; countans = 1; }
    }
    cout << ans << endl;
    cout << cans << endl;
    cout << countans << endl;
    return 0;
}