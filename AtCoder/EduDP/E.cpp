#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103,MAXS=1e5+3;
long long dp[MAXS],weight[MAXN];
int cost[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,w;
    cin>>n>>w;
    int sum=0;
    for(int i=1;i<=n;++i){
        cin>>weight[i]>>cost[i];
        sum+=cost[i];
    }
    for(int i=1;i<MAXS;++i){
        dp[i]=1e10;
    }
    for(int i=1;i<=n;++i){
        for(int i2=sum;i2>=cost[i];--i2){
            dp[i2]=min(dp[i2],dp[i2-cost[i]]+weight[i]);
        }
    }
    int res=0;
    for(int i=sum;i>=0;--i){
        if(dp[i]<=w){
            res=i;
            break;
        }
    }
    cout<<res<<endl;
return 0;
}