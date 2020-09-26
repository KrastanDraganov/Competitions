#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103,MAXM=1e6+3;
int coins[MAXN],dp[MAXM];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;++i){
        cin>>coins[i];
    }
    
    for(int sum=1;sum<=x;++sum){
        dp[sum]=MAXM;
        for(int i=0;i<n;++i){
            if(coins[i]<=sum){
                dp[sum]=min(dp[sum], dp[sum-coins[i]]+1);
            }
        }
    }

    cout<<(dp[x]==MAXM ? -1 : dp[x])<<endl;
return 0;
}