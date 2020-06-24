#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=53,MAXS=5e4+3;
int weights[MAXN],dp[MAXN][MAXS];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int all=0;
    for(int i=0;i<n;++i){
        cin>>weights[i];
        all+=weights[i];
    }

    for(int i=0;i<MAXN;++i){
        for(int i2=0;i2<MAXS;++i2){
            dp[i][i2]=1e9;
        }
    }

    dp[0][0]=weights[0];
    dp[0][weights[0]]=0;
    for(int i=1;i<n;++i){
        for(int sum=0;sum<=all;++sum){
            dp[i][sum]=min(dp[i][sum],dp[i-1][sum]+weights[i]);
            int new_sum1=abs(sum-weights[i]),new_sum2=sum+weights[i];
            dp[i][new_sum1]=min(dp[i][new_sum1],dp[i-1][sum]);
            dp[i][new_sum2]=min(dp[i][new_sum2],dp[i-1][sum]);
        }
    }
    cout<<dp[n-1][0]<<endl;
return 0;
}