#include<bits/stdc++.h>
using namespace std;
int n,a[100000],k,b[1000],minb;
int dp[20000][20000];
int f(int i,int j){
if(j<=i)return -1000000;
if(i+minb>=j)return 0;
if(dp[i][j]!=0)return dp[i][j];
for(int p=0;p<k;p++){
    dp[i][j]=max(dp[i][j],f(i+b[p],j)+a[i+b[p]]);
}
for(int p=0;p<k;p++){
    if(j-b[p]>=0)dp[i][j]=max(dp[i][j],f(i,j-b[p])+a[j-b[p]]);
}
return dp[i][j];
}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>a[i];
}
minb=10000000;
for(int i=0;i<k;i++){
    cin>>b[i];
    minb=min(minb,b[i]);
}
cout<<f(0,n-1)+a[0]+a[n-1]<<"\n";
return 0;
}

