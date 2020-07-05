#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103,MOD=1e8;
int dp[MAXN][MAXN][2];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;

    dp[0][0][0]=1;
    dp[0][0][1]=1;
    for(int i=0;i<=n1;++i){
        for(int i2=0;i2<=n2;++i2){
            if(i==0 and i2==0){
                continue;
            }
            for(int step=max(0,i-k1);step<i;++step){
                add_mod(dp[i][i2][0],dp[step][i2][1]);
            }
            for(int step=max(0,i2-k2);step<i2;++step){
                add_mod(dp[i][i2][1],dp[i][step][0]);
            }
        }
    }
    cout<<(dp[n1][n2][0]+dp[n1][n2][1])%MOD<<endl;
return 0;
}