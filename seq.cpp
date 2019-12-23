#include<bits/stdc++.h>
#define N 100005
using namespace std;
int nums[N],dp[4][N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    dp[2][0]=2*nums[0];
    dp[3][0]=3*nums[0];
    for(int i=1;i<n;i++){
        dp[2][i]=max(dp[2][i-1]+nums[i]*2,dp[3][i-1]+nums[i]*2);
        dp[3][i]=dp[2][i-1]+nums[i]*3;
    }
    cout<<max(dp[2][n-1],dp[3][n-1])<<endl;
return 0;
}
