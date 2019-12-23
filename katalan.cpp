#include<bits/stdc++.h> 
#define MOD 1000007
using namespace std; 
long long dp[2005];
int main(){ 
	int n;
    cin>>n;
    dp[0]=dp[1]=1;
    for(int i=2;i<=n-2;i++){
        dp[i]=0;
        for(int i2=0;i2<i;i2++){
            dp[i]+=((dp[i2]%MOD)*(dp[i-i2-1])%MOD)%MOD;
        }
    }
    cout<<dp[n-2]%MOD<<endl;
return 0; 
} 
