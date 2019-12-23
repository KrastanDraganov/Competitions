#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN = 1e5+3;
int nums[MAXN],dp[MAXN][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    dp[0][0]=dp[0][1]=nums[0];
    dp[1][0]=nums[1]+dp[0][0];
    dp[1][1]=-1e9;
    for(int i=2;i<n;++i){
        dp[i][0]=nums[i]+max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=nums[i]+dp[i-2][0];
    }
    int res=-1e9;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<2;++i2){
            res=max(res,dp[i][i2]);
        }
    }
    cout<<res<<endl;
return 0;
}