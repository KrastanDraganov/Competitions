#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<vector<long long>> dp(n+3, vector<long long>(m+3, 0));
    // dp[i][j] - number of ways to obtain sum #i 
    // with limit of the used numbers #j

    for(int sum=0;sum<=n;++sum){
        for(int num=0;num<=m;++num){
            if(sum==0 or sum==1 or num==1){
                dp[sum][num]=1;
                continue;
            }

            if(sum<num){
                dp[sum][num]=dp[sum][sum];
                continue;
            }
            
            dp[sum][num]=dp[sum-num][num]+dp[sum][num-1];
        }
    }

    cout<<dp[n][m]<<endl;
return 0;
}