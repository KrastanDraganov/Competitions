#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int p[400001], e[200001], beg[200001];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("cannons.out","w",stdout);
    freopen("cannons.in","r",stdin);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0;i<n;i++) {
        cin >> p[i*2] >> p[i*2+1];
        p[i*2]++;
        p[i*2+1]++;
        beg[i]=p[i*2];
        e[i]=p[i*2+1];
    }
    sort(e,e+n);
    sort(beg,beg+n);
    n*=2;
    sort(p,p+n);
    int points=0, l, br1, br2;
    br1=br2=0;
    for (int i=0;i<n;i++) {
        l=i;
        while (i<n && p[i]==p[l]) {
            if (beg[br1]==p[i]) {
                points++;
                br1++;
            }
            if (e[br2]==p[i]) {
                points--;
                br2++;
            }
            i++;
        }
        if (points>k) {
            cout << p[l]-1 << endl;
            return 0;
        }
        i--;
    }
    cout << m << endl;
    return 0;
}
