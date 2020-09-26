#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,MOD=1e9+7;
int dp[MAXN][MAXN];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            char cell;
            cin>>cell;
            
            if(cell=='*'){
                continue;
            }
            
            if(i==0 and i2==0){
                dp[0][0]=1;
            }
            
            if(i>0){
                add_mod(dp[i][i2],dp[i-1][i2]);
            }
            if(i2>0){
                add_mod(dp[i][i2],dp[i][i2-1]);
            }
        }
    }

    cout<<dp[n-1][n-1]<<endl;
return 0;
}