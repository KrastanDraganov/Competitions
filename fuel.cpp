#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN = 1e6+3,MOD = 1e9+7;
int fuels[MAXN],dp[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,l;
    cin>>n>>k>>l;
    fuels[0]=0;
    fuels[n+1]=k;
    for(int i=1;i<=n;++i){
        cin>>fuels[i];
    }
    int r=n+1,sum=1;
    dp[n+1]=1;
    for(int i=n;i>=0;--i){
        while(fuels[r]-fuels[i]>l){
            sum=(sum-dp[r]+MOD)%MOD;
            --r;
        }
        dp[i]=sum;
        sum=(sum+dp[i])%MOD;
    }
    cout<<dp[0]<<endl;
return 0;
}