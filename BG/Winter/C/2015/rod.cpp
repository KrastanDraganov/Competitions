#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=503;
int prefix[MAXN],dp[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    prefix[0]=0;
    for(int i=1;i<=n;++i){
        int weight;
        cin>>weight;
        prefix[i]=prefix[i-1]+weight;
    }
    
    for(int i=1;i<n;++i){
        dp[i][i+1]=prefix[i+1]-prefix[i-1];
    }
    for(int r=2;r<=n;++r){
        for(int l=1;l<=(n-r);++l){
            int curr=1e9;
            for(int i=l;i<(l+r);++i){
                curr=min(curr,dp[l][i]+dp[i+1][l+r]);
            }
            dp[l][l+r]=prefix[l+r]-prefix[l-1]+curr;
        }
    }
    cout<<dp[1][n]<<endl;
return 0;
}