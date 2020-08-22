#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
long long nums[MAXN],dp[MAXN][MAXN];

long long sol(int left, int right){
    if(left>right){ 
        return 0;
    }
    
    if(dp[left][right]!=0){ 
        return dp[left][right];
    }
    
    dp[left][right]=-1e18;
    dp[left][right]=max(dp[left][right],nums[left]+sol(left+1,right));
    dp[left][right]=max(dp[left][right],nums[right]+sol(left,right-1));
    
    if(right-left>=1){
        dp[left][right]=max(dp[left][right],nums[left]*nums[left+1]+sol(left+2,right));
        dp[left][right]=max(dp[left][right],nums[left]*nums[right]+sol(left+1,right-1));
        dp[left][right]=max(dp[left][right],nums[right]*nums[right-1]+sol(left,right-2));
    }
    
    if(right-left>=2){
        dp[left][right]=max(dp[left][right],nums[right]*nums[right-1]*nums[right-2]+sol(left,right-3));
        dp[left][right]=max(dp[left][right],nums[right]*nums[left]*nums[left+1]+sol(left+2,right-1));
        dp[left][right]=max(dp[left][right],nums[right]*nums[right-1]*nums[left]+sol(left+1,right-2));
        dp[left][right]=max(dp[left][right],nums[left]*nums[left+1]*nums[left+2]+sol(left+3,right));
    }
    
    return dp[left][right];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    
    cout<<sol(0,n-1)<<endl;
return 0;
}