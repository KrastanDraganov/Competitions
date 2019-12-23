#include<iostream>
#include<string.h>
#define endl '\n'
using namespace std;
int dp[10011],pref[2][10011];
const int mod=1e9+7;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,curr,prev1;
    cin >> n >> m ;
    dp[0]=1; pref[1][0]=1;
    for (i=1; i<=m; i++) {
        pref[1][i]=1;
        }
    for (i=2; i<=n; i++) {
        curr=i%2;
        prev1=(i-1)%2;
        for (j=0; j<=m; j++) {
            dp[j]=pref[prev1][j];
            if (j-i>=0) dp[j]=(dp[j]+mod-pref[prev1][j-i])%mod;
            pref[curr][j]=dp[j];
            if (j!=0) pref[curr][j]+=pref[curr][j-1];
            pref[curr][j]%=mod;
            }
        }
    cout << dp[m] ;
    cout << endl ;
    return 0;
}
