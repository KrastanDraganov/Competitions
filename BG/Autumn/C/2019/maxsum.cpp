#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MAXK=1e3+3;
int steps[MAXK],value[MAXN],dp[MAXN][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>value[i];
    }
    for(int i=0;i<k;++i){
        cin>>steps[i];
    }
    
    sort(steps,steps+k);
    dp[0][0]=dp[0][1]=value[0];
    int max_left=value[0];
    for(int i=1;i<n;++i){
        dp[i][0]=-1e8;
        dp[i][1]=max_left+value[i];
        for(int i2=0;i2<k and i-steps[i2]>=0;++i2){
            dp[i][0]=max(dp[i][0],dp[i-steps[i2]][0]+value[i]);
            dp[i][1]=max(dp[i][1],dp[i-steps[i2]][1]+value[i]);
        }
        max_left=max(max_left,dp[i][0]);
    }
    
    cout<<dp[n-1][1]<<endl;
return 0;
}