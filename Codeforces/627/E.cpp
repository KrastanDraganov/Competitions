#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e3+3;
int dp[MAXN][MAXN],length[MAXN];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    for(int i=0;i<n;++i){
        cin>>length[i];
    }
    for(int i=0;i<MAXN;++i){
        for(int i2=0;i2<MAXN;++i2){
            dp[i][i2]=-1e8;
        }
    }
    dp[0][0]=0;
    int sum=0;
    for(int i=1;i<=n;++i){
        sum+=length[i-1];
        for(int i2=0;i2<=n;++i2){
            int curr=sum-i2;
            dp[i][i2]=max(dp[i][i2],dp[i-1][i2]+((curr%h)>=l and (curr%h)<=r));
            if(i2<n){
                --curr;
                dp[i][i2+1]=max(dp[i][i2+1],dp[i-1][i2]+((curr%h)>=l and (curr%h)<=r));
            }
        }
    }
    int res=0;
    for(int i=0;i<=n;++i){
        res=max(res,dp[n][i]);
    }
    cout<<res<<endl;
return 0;
}