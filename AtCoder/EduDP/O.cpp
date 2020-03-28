#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=21,MOD=1e9+7;
bool check[MAXN][MAXN];
int dp[(1<<MAXN)+3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cin>>check[i][i2];
        }
    }
    dp[0]=1;
    for(int mask=0;mask<(1<<n)-1;++mask){
        int men=__builtin_popcount(mask);
        for(int women=0;women<n;++women){
            if(check[men][women] and !(mask & (1<<women))){
                int new_mask=(mask | (1<<women));
                dp[new_mask]=(dp[new_mask]+dp[mask])%MOD;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
return 0;
}