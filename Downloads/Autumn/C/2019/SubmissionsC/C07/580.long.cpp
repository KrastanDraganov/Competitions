#include <bits/stdc++.h>
using namespace std;
int n, l, k;
string s[10010];
string dp[105][105];
int curr;
queue < string > q;
string choice[3];
bool sortf(string a, string b) {
    if (a == "") return 1;
    if (b == "") return 0;
    if (a.size() > b.size()) return 0;
    if (a.size() < b.size()) return 1;
    if (a > b) return 1;
    return 0;
}
string currbla;
void common(const string &a, const string &b) {
    for (int i = 0 ; i <= a.size() ; ++i) {
        for (int j = 0 ; j <= b.size() ; ++j) {
            dp[i][j] = "";
        }
    }
    for (int i = 1 ; i <= a.size() ; ++i) {
        for (int j = 1 ; j <= b.size() ; ++j) {
            currbla = dp[i-1][j-1];
            if (a[i-1] == b[j-1]) currbla += a[i-1];
            choice[0] = currbla;
            choice[1] = dp[i-1][j];
            choice[2] = dp[i][j-1];
            sort(choice, choice+3, sortf);
            dp[i][j] = choice[2];
        }
    }
}
pair <string, int> f(string match, bool bl) {
    int ret = 0;
    for (int i = 0 ; i < n ; ++i) {
        common(match, s[i]);
        if (dp[match.size()][s[i].size()].size() >= k) {
            match = dp[match.size()][s[i].size()];
            ++ret;
        } else if (bl) q.push(s[i]);
    }
    return {match, ret};
}
pair <string, int> res = {"", 0};
int third_outp = 0;
int main () {
    common("fagcbdaga", "dcdfb");
    cin >> n >> l >> k;
    for (int i = 0 ; i < n ; ++i) cin >> s[i];
    q.push(s[0]);
    bool bl = 1;
    while (!q.empty()) {
        auto curr = f(q.front(), bl);
        q.pop();
        if (curr.second > res.second) {
                third_outp=1;
            res = curr;
        } else {
            if (curr.second == res.second) {
                ++third_outp;
                if (res.first > curr.first)res = curr;
            }
        }
        bl = 0;
    }
    cout << res.second << '\n' << res.first << '\n' << third_outp << '\n';
    return 0;
}
