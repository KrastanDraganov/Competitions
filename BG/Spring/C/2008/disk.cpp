#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=23;
long long dp[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    cin>>n>>k;

    for(int i=0;i<=k;++i){
        dp[0][i]=1ll;
    }
    for(int i=1;i<=n;++i){
        for(int i2=i;i2<=n and i2<=i+k;++i2){
            dp[i][i2]=dp[i][i2-1]+dp[i-1][i2];
        }
    }

    cout<<dp[n][n]<<endl;
return 0;
}