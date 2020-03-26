#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=3e3+3;
long long nums[MAXN],dp[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>nums[i];
        dp[i][i]=nums[i];
    }
    for(int l=n;l>=1;--l){
        for(int r=l;r<=n;++r){
            dp[l][r]=max(nums[l]-dp[l+1][r],nums[r]-dp[l][r-1]);
        }
    }
    cout<<dp[1][n]<<endl;
return 0;
}