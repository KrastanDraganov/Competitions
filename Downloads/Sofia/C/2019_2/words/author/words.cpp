#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool matchIndex[100001];
long long startPrefix[100001];
long long answerPrefix[100001];

void matches(const string& s, const string& w) {
    for (int i = s.find(w, 0); i != -1; i = s.find(w, i+1)) {
        matchIndex[i+1]=true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, w; cin >> s >> w;

    for (int i = s.find(w, 0); i != -1; i = s.find(w, i+1)) matchIndex[i+1]=true;
    for (int i = 1; i <= s.size(); i++) startPrefix[i]=startPrefix[i-1]+matchIndex[i];
    for (int i = w.size(); i <= s.size(); i++) {
        answerPrefix[i]=answerPrefix[i-1]+matchIndex[i]*startPrefix[i-w.size()];
    }

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        long long ans = 0;
        if (b-a+1 >= 2*w.size()) {
            ans += answerPrefix[b-w.size()+1]-answerPrefix[a+w.size()-1];
            ans -= startPrefix[a-1]*(startPrefix[b-w.size()+1]-startPrefix[a+w.size()-1]);
        }
        cout << ans << endl;
    }

    return 0;
}
