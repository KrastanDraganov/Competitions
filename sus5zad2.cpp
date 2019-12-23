#include<bits/stdc++.h>
#define BORDER 10000005
using namespace std;
long long dp[BORDER];
long long f(int r,int n){
    long long rez=BORDER;
    if(r<=n)return 1;
    for(int i=n;i>=1;i--){
        if(i>1 and r%i==0) rez=min(rez,dp[r/i]);
        rez=min(rez,dp[r-i]);
    }
    return rez+1;
}
int main(){
    int r,n;
    cin>>r>>n;
    for(int i=1;i<=r;i++){
        dp[i]=f(i,n);
    }
    cout<<dp[r]<<endl;
    return 0;
}