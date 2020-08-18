#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103,MOD=1e9+7;
int dp[MAXN][(1<<10)+3];

bool check(int mask1, int mask2, int m){
    int counter=0;
    for(int i=0;i<m;++i){
        if(mask2 & (1<<i)){
            if((mask1 & (1<<i)) or counter%2){
                return false;
            }
            counter=0;
        }else if(mask1 & (1<<i)){
            if(counter%2){
                return false;
            }
            counter=0;
        }else{
            ++counter;
        }
    }
    return !(counter%2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    
    if(n<m){
        swap(n,m);
    }
    
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int i2=0;i2<(1<<m);++i2){
            for(int i3=0;i3<(1<<m);++i3){
                if(check(i3,i2,m)){
                    dp[i][i2]=(dp[i][i2]+dp[i-1][i3])%MOD;
                }
            }
        }
    }
    cout<<dp[n][0]<<endl;
return 0;
}