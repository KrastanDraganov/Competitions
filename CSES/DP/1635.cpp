#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103,MAXM=1e6+3,MOD=1e9+7;
int coins[MAXN],dp[MAXM];

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
    
    dp[0]=1;
    for(int sum=1;sum<=x;++sum){
        for(int i=0;i<n;++i){
            if(coins[i]<=sum){
                add_mod(dp[sum], dp[sum-coins[i]]);
            }
        }
    }

    cout<<dp[x]<<endl;
return 0;
}