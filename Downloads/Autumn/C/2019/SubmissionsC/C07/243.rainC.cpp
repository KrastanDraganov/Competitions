#include <bits/stdc++.h>
using namespace std;
int n, k;
pair < int, int > p[1048576];
int a[1048576];
int next_bigger[1048576];
stack < pair < int, int > > s;
bool polezno(int ix) {
    return (a[ix-1] >= a[ix]) ^ (a[ix+1] >= a[ix]);
}
int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1 ; i <= n ; ++i) cin >> a[i];
    cin >> k;
    for (int i = 0 ; i < k ; ++i) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p+k);
    for (int i = 0 ; i < k ; ++i) {
        a[p[i].second+1] += p[i].first;
    }
    int obem = 0, sum = 0, mxcurr = 0;
    for (int i = 0 ; i < k ; ++i) {
        if (polezno(p[i].second+1)) ++sum;
        else a[p[i].second+1] -= p[i].first;
    }
    int curr;
    for (int i = 1 ; i <= n + 1 ; ++i) {
        if (i == n + 1) curr = 1048576;
        else curr = a[i];
        while (!s.empty() && s.top().first <= curr) {
            next_bigger[s.top().second] = i;
            s.pop();
        }
        s.push({a[i], i});
    }
    for (int i = 1 ; i < n ; ++i) {
        if (next_bigger[i] == n+1) obem += a[i+1];
        else {
            obem += (next_bigger[i] - i)*a[i];
            i = next_bigger[i] - 1;
        }
    }
    cout << sum << ' ' << obem << '\n';
    return 0;
}
