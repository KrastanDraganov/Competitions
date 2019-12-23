#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
int perm[1001];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,ans=0,cnt,i,j;
    cin >> n >> m ;
    for (i=0; i<n; i++) {
        perm[i]=i+1;
        }
    for (;;) {
        cnt=0;
        for (i=0; i<n; i++) {
            for (j=0; j<i; j++) {
                if (perm[j]>perm[i]) cnt++;
                if (cnt>m) break;
                }
            if (cnt>m) break;
            }
        if (cnt==m) ans++;
        if (next_permutation(perm,perm+n)==0) break;
        }
    cout << ans ;
    cout << endl ;
    return 0;
}
