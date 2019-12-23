#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
long long int dp[100001],br[100001];
int main () {
    string s,w;
    int i,j,n,m,fl,q,l,r;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s ;
    cin >> w ;
    n=s.size();
    m=w.size();
    for (i=m-1; i<n; i++) {
        fl=0;
        for (j=0; j<m; j++) {
            if (s[i-m+1+j]!=w[j]) {
               fl++;
               break;
               }
            }
        br[i]=fl^1;
        }
    for (i=m; i<n; i++) {
        if (br[i]==1) dp[i]=br[i-m];
        dp[i]+=dp[i-1];
        br[i]+=br[i-1];
        }
    cin >> q ;
    for (i=1; i<=q; i++) {
        cin >> l >> r ;
        l--; r--;
        if ((r-l+1)<2*m) {
           cout << 0 << endl ;
           continue;
           } //cout << (dp[r]-dp[l+2*m-2]) << " ";
        if (l==0) cout << dp[r] << endl ;
        else cout << (dp[r]-dp[l+2*m-2])-(br[r]-br[l+2*m-2])*br[l+m-2] << endl ;
        //cout << ans[r]-ans[l+m-2] << endl ;
        }
    return 0;
}
