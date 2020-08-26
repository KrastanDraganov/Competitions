#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=703;
long long nums[MAXN],dp[MAXN][MAXN];

long long sol(int l, int r){
    long long& ans=dp[l][r];
    if(ans!=-1){
        return ans;
    }
    if(l+1==r){
        return 0;
    }
    for(int i=l+1;i<r;++i){
        ans=max(ans,nums[i]*(nums[l]+nums[r])+sol(l,i)+sol(i,r));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    
    for(int r=2;r<n;++r){
        for(int l=0;l+r<n;++l){
            for(int i=l+1;i<(l+r);++i){
                dp[l][l+r]=max(dp[l][l+r],nums[i]*(nums[l]+nums[l+r])+dp[l][i]+dp[i][l+r]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
return 0;
}