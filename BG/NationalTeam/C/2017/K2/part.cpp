#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,MOD=1e9+7;
int dp[MAXN][MAXN];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    dp[1][1]=1;
    for(int curr=2;curr<=n;++curr){
        for(int i=1;i<=min(curr,k);++i){
            dp[curr][i]=dp[curr-1][i-1];
            add_mod(dp[curr][i],dp[curr-i][i]);
        }
    }
    cout<<dp[n][k]<<endl;
return 0;
}