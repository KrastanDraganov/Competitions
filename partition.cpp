#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=203,MAXS=2e5+3;
int nums[MAXN];
bool dp[MAXN][MAXS];

bool check(int n, int sum){
    if(sum%2==1){
        return false;
    }
    sum/=2;
    dp[0][0]=true;
    for(int i2=1;i2<=sum;++i2){
        dp[0][i2]=false;
    }
    for(int i=1;i<=n;++i){
        for(int curr=0;curr<=sum;++curr){
            dp[i][curr]=dp[i-1][curr];
            if(nums[i-1]<=curr){
                dp[i][curr]|=dp[i-1][curr-nums[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;++i){
            cin>>nums[i];
            sum+=nums[i];
        }
        cout<<check(n,sum)<<endl;
    }
return 0;
}