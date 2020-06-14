#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103;
long long height[MAXN][MAXN],dp[MAXN][MAXN];

void calc_dp(int n, int m, long long start_height){
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            dp[i][i2]=1e18;
        }
    }
    dp[0][0]=height[0][0]-start_height;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            long long diff=height[i][i2]-(start_height+i+i2);
            if(diff<0){
                continue;
            }
            if(i>0){
                dp[i][i2]=min(dp[i][i2],dp[i-1][i2]+diff);
            }
            if(i2>0){
                dp[i][i2]=min(dp[i][i2],dp[i][i2-1]+diff);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i){
            for(int i2=0;i2<m;++i2){
                cin>>height[i][i2];
            }
        }

        long long res=1e18;
        for(int i=0;i<n;++i){
            for(int i2=0;i2<m;++i2){
                long long curr=height[i][i2]-i-i2;
                if(curr>height[0][0]){
                    continue;
                }
                calc_dp(n,m,curr);
                res=min(res,dp[n-1][m-1]);
            }
        }
        cout<<res<<endl;
    }
return 0;
}