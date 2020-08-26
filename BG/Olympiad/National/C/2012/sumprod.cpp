#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=12348;
long long dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long m;
    cin>>n>>m>>dp[0];
    
    for(int i=1;i<n;++i){
        long long num;
        cin>>num;
        dp[i]=(dp[i-1]*num)%m;
        for(int i2=i-1;i2>0;--i2){
            dp[i2]=(dp[i2-1]*num+dp[i2])%m;
        }
        dp[0]=(dp[0]+num)%m;
    }
    
    long long res=0;
    for(int i=0;i<n;++i){
        res=max(res,dp[i]);
    }
    cout<<res<<endl;
return 0;
}