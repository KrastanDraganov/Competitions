#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e6+3,MOD=1e9+7;
int dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    cin>>n>>k;
    
    int sum=1;
    dp[0]=1;
    
    for(int i=1;i<=n;++i){
        dp[i]=sum;
        sum=(sum+dp[i])%MOD;
        if(i>=k){
            sum=(sum+(MOD-dp[i-k]))%MOD;
        }
    }
    cout<<dp[n]<<endl;
return 0;
}