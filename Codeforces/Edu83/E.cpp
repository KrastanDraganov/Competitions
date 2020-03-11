#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=503;
int dp[MAXN][MAXN],min_nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        dp[i][i]=num;
    }
    for(int i=n-2;i>=0;--i){
        for(int i2=i+1;i2<n;++i2){
            for(int i3=i;i3<i2;++i3){
                if(dp[i][i3]>=0 and dp[i][i3]==dp[i3+1][i2]){
                    dp[i][i2]=dp[i][i3]+1;
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        min_nums[i]=1e9;
        for(int i2=0;i2<i;++i2){
            if(dp[i2][i-1]>=0){
                min_nums[i]=min(min_nums[i],min_nums[i2]+1);
            }
        }
    }
    cout<<min_nums[n]<<endl;
return 0;
}