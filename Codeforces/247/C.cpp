#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=103,MOD=1e9+7;
int dp[MAXN][2];

int dfs(int sum, int k, int d){
    if(sum<d){
        return 0;
    }
    if(sum==0){
        return 1;
    }
    if(dp[sum][d>0]!=0){
        return dp[sum][d>0];
    }
    int& res=dp[sum][d>0];
    for(int i=1;i<=k;++i){
        res+=dfs(sum-i,k,(i<d ? d : 0));
        if(res>=MOD){
            res-=MOD;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k,d;
    cin>>n>>k>>d;

    cout<<dfs(n,k,d)<<endl;
return 0;
}