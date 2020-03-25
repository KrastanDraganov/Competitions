#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int dp[3][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int a,b,c;
        cin>>a>>b>>c;
        dp[0][i]=max(dp[2][i-1],dp[1][i-1])+a;
        dp[1][i]=max(dp[2][i-1],dp[0][i-1])+b;
        dp[2][i]=max(dp[0][i-1],dp[1][i-1])+c;
    }
    int res=0;
    for(int i=0;i<3;++i){
        res=max(res,dp[i][n]);
    }
    cout<<res<<endl;
return 0;
}