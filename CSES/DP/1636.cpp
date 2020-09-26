#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103,MAXM=1e6+3,MOD=1e9+7;
int coins[MAXN],dp[MAXN][MAXM];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;++i){
        cin>>coins[i];
    }
    
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int sum=0;sum<=x;++sum){
            dp[i][sum]=dp[i-1][sum];
            if(coins[i-1]<=sum){
                add_mod(dp[i][sum], dp[i][sum-coins[i-1]]);
            }
        }
    }

    cout<<dp[n][x]<<endl;
return 0;
}