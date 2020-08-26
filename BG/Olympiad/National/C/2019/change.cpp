#include<iostream>
#include<algorithm>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXS=2e4+3,MAXN=103;
int dp[MAXS],coins[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s,n;
    cin>>s>>n;
    for(int i=0;i<n;++i){
        cin>>coins[i];
    }
    
    for(int i=1;i<MAXS;++i){
        dp[i]=i;
    }
    
    int res=s;
    for(int i=1;i<MAXS;++i){
        for(int i2=0;i2<n;++i2){
            if(coins[i2]<=i){
                dp[i]=min(dp[i],dp[i-coins[i2]]+1);
            }
        }
        if(i>=s){
            res=min(res,dp[i]+dp[i-s]);
        }
    }
    cout<<res<<endl;
return 0;
}