#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=503;
int dp[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<=n;++i){
        for(int i2=0;i2<=m;++i2){
            if(i==i2){
                dp[i][i2]=0;
                continue;
            }
            
            dp[i][i2]=MAXN*MAXN;

            for(int cut=1;cut<i;++cut){
                dp[i][i2]=min(dp[i][i2],dp[i-cut][i2]+dp[cut][i2]+1);
            }

            for(int cut=1;cut<i2;++cut){
                dp[i][i2]=min(dp[i][i2],dp[i][i2-cut]+dp[i][cut]+1);
            }
        }
    }

    cout<<dp[n][m]<<endl;
return 0;
}