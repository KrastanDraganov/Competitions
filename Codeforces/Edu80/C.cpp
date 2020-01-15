#include<iostream>
#define endl '\n'
using namespace std;
const int MOD=1e9+7;
long long dp[1003][13];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        dp[i][1]=1;
    }
    for(int i=2;i<=m;++i){
        for(int i2=1;i2<=n;++i2){
            dp[i2][i]=0;
            for(int i3=i2;i3>=1;--i3){
                dp[i2][i]=(dp[i2][i]+(i2-i3+1)*dp[i3][i-1])%MOD;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;++i){
        res=(res+(n-i+1)*dp[i][m])%MOD;
    }
    cout<<res<<endl;
return 0;
}