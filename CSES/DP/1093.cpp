#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=503,MOD=1e9+7;
int dp[MAXN][MAXN*MAXN/2];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int calc_ways(int n){
    int target=(n*(n+1))/2;
    
    if(target%2==1){
        return 0;
    }
    target/=2;

    dp[0][0]=1;
    for(int num=1;num<n;++num){
        for(int sum=0;sum<=target;++sum){
            dp[num][sum]=dp[num-1][sum];
            if(num<=sum){
                add_mod(dp[num][sum],dp[num-1][sum-num]);
            }
        }
    }
    
    return dp[n-1][target];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    cout<<calc_ways(n)<<endl;
return 0;
}