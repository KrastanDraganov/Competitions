#include<iostream>
using namespace std;
const int mod=1e9+7;
int dp[2000001];
int main () {
    int n,k,i,sum=0;
    cin >> n >> k ;
    dp[0]=1; sum=1;
    for (i=1; i<k; i++) {
        dp[i]=sum;
        sum+=dp[i];
        sum%=mod;
        }
    for (i=k; i<=n; i++) {
        dp[i]=sum;
        sum+=dp[i]; sum%=mod;
        sum+=(mod-dp[i-k]); sum%=mod;
        }
    cout << dp[n] ;
    cout << endl ;
    return 0;
}
