#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int nums[MAXN],dp[4][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
