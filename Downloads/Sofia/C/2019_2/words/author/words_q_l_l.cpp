#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool match(const string& s, const string& w, int start) {
    for (int i = 0; i < w.size(); i++) {
        if (start+i >= s.size()) return false;
        if (w[i] != s[start+i]) return false;
    }
    return true;
}

vector<int> matches(const string& s, const string& w) {
    vector<int> ans;
    for (int i = 0; i < s.size(); i++) {
        if (match(s,w,i)) ans.push_back(i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, w; cin >> s >> w;

    vector<int> m = matches(s, w);

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b; a--; b--;
        long long ans = 0;
        for (int i = 0; i < m.size(); i++) {
            if (m[i]<a || m[i]+w.size()-1 > b) continue;

            for (int j = i+1; j < m.size(); j++) {
                if (m[j]<a || m[j]+w.size()-1 > b) continue;

                if (m[i]+w.size() <= m[j]) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
