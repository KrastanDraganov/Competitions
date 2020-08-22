#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=203;
const long long MOD = 1ull<<62;
long long dp[MAXN][MAXN][2*MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,p;
    cin>>n>>m>>p;
    
    if(p<m){
        cout<<0<<endl;
        return 0;
    }
    
    for(int i=0;i<m;++i){
        dp[0][i][i+1]=1;
    }
    for(int i=0;i<n;++i){
        dp[i][0][i+1]=1;
    }
    
    for(int i=1;i<n;++i){
        for(int i2=1;i2<m;++i2){
            for(int i3=2;i3<=p;++i3){
                dp[i][i2][i3]=(dp[i-1][i2][i3-1]+dp[i][i2-1][i3-1]+dp[i-1][i2-1][i3-1])%MOD;
            }
        }
    }
    cout<<dp[n-1][m-1][p]<<endl;
return 0;
}