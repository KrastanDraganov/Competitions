#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN=1e3+3,MOD=1e9+7;
int dp[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x,y;
    cin>>n>>x>>y;
    dp[2][1]=1;
    for(int i=3;i<=n;++i){
        for(int i2=1;i2<=(i/2);++i2){
            dp[i][i2]=1;
            for(int i3=1;i3<i2;++i3){
                dp[i][i2]+=dp[i-i3][i2-i3];
                if(dp[i][i2]>=MOD){
                    dp[i][i2]-=MOD;
                }
            }
            for(int i3=i2+1;i3<i;++i3){
                dp[i][i2]+=dp[i3][i2];
                if(dp[i][i2]>=MOD){
                    dp[i][i2]-=MOD;
                }
            }
            dp[i][i-i2]=dp[i][i2];
        }
    }
    cout<<dp[n][y-x]<<endl;
return 0;
}