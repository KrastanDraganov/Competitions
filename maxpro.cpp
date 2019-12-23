#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long dp[205][205];
long long sol(long long sum,int number){
    if(sum==0) return 1;
    if(sum<0 or number==0) return 0;
    if(dp[sum][number]!=0) return dp[sum][number];
    dp[sum][number]=max(sol(sum,number-1),sol(sum-number,number-1)*number);
    return dp[sum][number];
}
int main(){
    int n;
    cin>>n;
    cout<<sol(n,n)<<endl;
return 0;
}