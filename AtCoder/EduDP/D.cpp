#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103,MAXW=1e5+3;
long long cost[MAXN],dp[MAXN][MAXW];
int weight[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;++i){
        cin>>weight[i]>>cost[i];
    }
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=w;++i2){
            if(weight[i]>i2){
                dp[i][i2]=dp[i-1][i2];
            }else{
                dp[i][i2]=max(cost[i]+dp[i-1][i2-weight[i]],dp[i-1][i2]);
            }
        }
    }
    cout<<dp[n][w]<<endl;
return 0;
}