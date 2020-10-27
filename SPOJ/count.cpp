#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3,MOD=1988;
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

    int n,k;
    while(cin>>n and cin>>k){
        if(n==0 and k==0){
            break;
        }

        for(int i=0;i<=n;++i){
            for(int i2=0;i2<=k;++i2){
                dp[i][i2]=0;
            }
        }
        
        dp[0][0]=1;
        for(int nums=1;nums<=n;++nums){
            for(int trucks=1;trucks<=min(k, nums);++trucks){
                add_mod(dp[nums][trucks], dp[nums-trucks][trucks]);
                add_mod(dp[nums][trucks], dp[nums-1][trucks-1]);
            }
        }
        
        cout<<dp[n][k]<<endl;
    }
return 0;
}