#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

long long dp[100001],otg[100001],red[100001],poz[100001];

int main(){

ios_base::sync_with_stdio(false);
cin.tie();

long long n,m,a;
cin>>n>>m;
for(int i=0;i<n;i++)cin>>red[i];
for(int i=0;i<m;i++)cin>>poz[i];
sort(poz,poz+m);

dp[0]=red[0];
otg[0]=red[0];
for(int i=1;i<n;i++){
    dp[i]=dp[i-1];
    for(int j=0;j<m && poz[j]<=i;j++){
        dp[i]=max(dp[i],dp[i-poz[j]]+red[i]);
    }
}
for(int i=1;i<n;i++){
    otg[i]=dp[i-1]+red[i];
    for(int j=0;j<m && poz[j]<=i;j++){
        otg[i]=max(otg[i],otg[i-poz[j]]+red[i]);
    }
}
cout<<otg[n-1]<<endl;

return 0;
}
