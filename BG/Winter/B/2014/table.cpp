#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int dp[MAXN];

void add_mod(int& x, int y, int mod){
    x+=y;
    if(x>=mod){
        x-=mod;
    }
}

int mul_mod(int x, int y, int mod){
    return 1ll*x*y%mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,mod;
    cin>>n>>mod;
    n/=2;

    dp[0]=dp[1]=1;
    for(int i=2;i<=n;++i){
        for(int i2=0;i2<i;++i2){
            add_mod(dp[i], mul_mod(dp[i2], dp[i-i2-1], mod), mod);
        }
    }

    cout<<dp[n]<<endl;
return 0;
}