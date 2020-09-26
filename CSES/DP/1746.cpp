#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MAXM=103,MOD=1e9+7;
int nums[MAXN],dp[MAXN][MAXM];
int limits[3]={-1,0,1};

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    if(nums[0]==0){
        for(int i=1;i<=m;++i){
            dp[0][i]=1;
        }
    }else{
        dp[0][nums[0]]=1;
    }

    for(int i=1;i<n;++i){
        if(nums[i]>0){
            for(int diff : limits){
                int prev=nums[i]+diff;
                add_mod(dp[i][nums[i]],dp[i-1][prev]);
            }
            continue;
        }
        for(int curr=1;curr<=m;++curr){
            for(int diff : limits){
                int prev=curr+diff;
                add_mod(dp[i][curr],dp[i-1][prev]);
            }
        }
    }

    int res=0;
    for(int i=1;i<=m;++i){
        add_mod(res,dp[n-1][i]);
    }
    cout<<res<<endl;
return 0;
}