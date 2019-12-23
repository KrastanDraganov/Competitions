#include<iostream>
#include<string.h>
#define endl '\n'
using namespace std;
long long int dp[1001][10011];
const long long int mod=1e9+7;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,h,ind1,ind2;
    cin >> n >> m ;
    dp[1][0]=1;
    for (i=2; i<=n; i++) {
        ind1=min(i*(i-1)/2,m);
        for (j=0; j<=ind1; j++) {
            ind2=max(0,j-(i-1));
            for (h=j; h>=ind2; h--) {
                dp[i][j]+=dp[i-1][h];
                }
            dp[i][j]%=mod;
            }
        }
    cout << dp[n][m] ;
    cout << endl ;
    return 0;
}
