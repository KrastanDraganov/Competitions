#include<iostream>
#include<string.h>
#define endl '\n'
using namespace std;
int dp[1001][10011],pref[1001][10011];
const int mod=1e9+7;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j;
    cin >> n >> m ;
    dp[1][0]=1; pref[1][0]=1;
    for (i=1; i<=m; i++) {
        pref[1][i]=1;
        }
    for (i=2; i<=n; i++) {
        for (j=0; j<=m; j++) {
            dp[i][j]+=pref[i-1][j];
            if (j-i>=0) dp[i][j]=(dp[i][j]+mod-pref[i-1][j-i])%mod;
            pref[i][j]+=dp[i][j];
            if (j!=0) pref[i][j]+=pref[i][j-1];
            pref[i][j]%=mod;
            }
        }
    cout << dp[n][m] ;
    cout << endl ;
    return 0;
}
