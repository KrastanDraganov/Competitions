#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3;
int dp[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin>>a>>b;

    int n=(int) a.size();
    int m=(int) b.size();

    for(int i=0;i<=n;++i){
        for(int i2=0;i2<=m;++i2){
            dp[i][i2]=MAXN;
        }
    }
    dp[0][0]=0;

    for(int i=0;i<=n;++i){
        for(int i2=0;i2<=m;++i2){
            if(i>0){
                dp[i][i2]=min(dp[i][i2], dp[i-1][i2]+1);
            }
            
            if(i2>0){
                dp[i][i2]=min(dp[i][i2], dp[i][i2-1]+1);
            }

            if(i>0 and i2>0){
                bool is_diff=(a[i-1]!=b[i2-1]);
                dp[i][i2]=min(dp[i][i2], dp[i-1][i2-1]+is_diff);
            }
        }
    }

    cout<<dp[n][m]<<endl;
return 0;
}