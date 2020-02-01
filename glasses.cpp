#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3,MOD=1e6,BORDER=1000;
int dp[MAXN][BORDER+3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin>>k;
    dp[9][0]=2;
    for(int i=10;i<k;++i){
        for(int i2=0;i2<min(i,BORDER);++i2){
            dp[i][0]=(dp[i][0]+dp[i-10][i2])%MOD;
            if(i2>0){
                dp[i][i2]=dp[i-1][i2-1];
            }
        }
    }
    int res=0;
    for(int i=0;i<min(k,BORDER);++i){
        res=(res+dp[k-1][i])%MOD;
    }
    cout<<res<<endl;
return 0;
}