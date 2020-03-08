#include<iostream>
#include<vector>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,MOD=1e9+9;
int dp[MAXN][MAXN];
vector<int> divisors[MAXN];

int sol(int ind, int num, int n){
    if(ind>=n){
        return 1;
    }
    if(dp[ind][num]!=-1){
        return dp[ind][num];
    }
    int ans=0;
    for(int next : divisors[num]){
        ans=(ans+sol(ind+1,next,n))%MOD;
    }
    return dp[ind][num]=ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;++i){
        for(int i2=1;i2<=k;++i2){
            if(i%i2==0 or i2%i==0){
                divisors[i].push_back(i2);
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<sol(0,1,n)<<endl;
return 0;
}