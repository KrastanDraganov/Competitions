#include<iostream>
#include<stdio.h>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=503,MAXSUM=125e3+3;
int nums[MAXN],sum;
bool dp[MAXN][MAXSUM];

bool check(int n){
    if(sum%2==1){
        return false;
    }
    sum/=2;
    
    for(int i=1;i<=n;++i){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;++i){
        for(int curr=1;curr<=sum;++curr){
            dp[i][curr]=dp[i-1][curr];
            if(nums[i-1]<=curr){
                dp[i][curr]=(dp[i][curr] or dp[i-1][curr-nums[i-1]]);
            }
        }
    }
    return dp[n][sum];
}

int main(){
    freopen("equation.in","r",stdin);
    freopen("equation.out","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        sum+=nums[i];
    }

    sort(nums,nums+n);
    cout<<(check(n) ? "YES" : "NO")<<endl;
return 0;
}