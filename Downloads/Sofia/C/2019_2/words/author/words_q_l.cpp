#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

string s, w;
long long matchPrefix[100001];

bool isMatch(const string& s, const string& w, int start) {
    for (int i = 0; i < w.size(); i++) {
        if (start+i >= s.size()) return false;
        if (w[i] != s[start+i]) return false;
    }
    return true;
}

void findMatches(const string& s, const string& w) {
    for (int i = 0; i < s.size(); i++) {
        matchPrefix[i+1] = matchPrefix[i]+isMatch(s,w,i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> w;
    findMatches(s, w);

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        long long ans = 0;

        for (int i = a; i+w.size()-1 <= b; i++) {
            if (matchPrefix[i] == matchPrefix[i-1]) continue;
            if (i < w.size()) continue;
            if (i-w.size() < a) continue;

            ans += matchPrefix[i-w.size()]-matchPrefix[a-1];
        }

        cout << ans << endl;
    }

    return 0;
}
