#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,MOD=1e9+7;
long long dp[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=m;++i2){
            char curr;
            cin>>curr;
            if(curr=='.'){
                if(i==1 and i2==1){
                    dp[i][i2]=1;
                }else{
                    dp[i][i2]=(dp[i-1][i2]+dp[i][i2-1])%MOD;
                }
            }else{
                dp[i][i2]=0;
            }
        }
    }
    cout<<dp[n][m]<<endl;
return 0;
}