#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int dp[205][205];
int sol(string s1,string s2,int n,int m){
    //cout<<n<<" "<<m<<" "<<s1[n-1]<<" "<<s2[m-1]<<endl;
    if(dp[n][m]!=-1) return dp[n][m];
    if(n==0) return m;
    if(m==0) return n;
    if(s1[n-1]==s2[m-1]){
        dp[n][m]=sol(s1,s2,n-1,m-1);
        return dp[n][m];
    }
    dp[n][m]=min(sol(s1,s2,n-1,m),sol(s1,s2,n,m-1))+1;
    return dp[n][m];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin>>tests;
    for(int i=0;i<tests;i++){
        string s1="";
        int k;
        cin>>k>>s1;
        string s2=s1;
        reverse(s2.begin(),s2.end());
        memset(dp,-1,sizeof(dp));
        int res=sol(s1,s2,s1.size(),s2.size());
        //cout<<s1<<" "<<s2<<" "<<res<<" ";
        if(res<=2*k){
            cout<<1;
        }else{
            cout<<0;
        }
        //cout<<endl;
    }
    cout<<endl;
return 0;
}