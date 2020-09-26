#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3,MOD=1e9+7;
int dp[MAXN];

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

    dp[0]=1;
    for(int i=1;i<=n;++i){
        for(int dice=1;dice<=min(6,i);++dice){
            add_mod(dp[i], dp[i-dice]);
        }
    }

    cout<<dp[n]<<endl;
return 0;
}