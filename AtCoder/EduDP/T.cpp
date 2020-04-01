#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=3e3+3,MOD=1e9+7;
int dp[MAXN][MAXN],prefix[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string signs;
    cin>>n>>signs;

    dp[1][1]=1;
    for(int len=2;len<=n;++len){
        for(int i=1;i<len;++i){
            prefix[len-1][i]=(prefix[len-1][i-1]+dp[len-1][i])%MOD;
        }
        for(int curr=1;curr<=len;++curr){
            int l,r;
            if(signs[len-2]=='>'){
                l=curr;
                r=len-1;
            }else{
                l=1;
                r=curr-1;
            }
            dp[len][curr]=(dp[len][curr]+(prefix[len-1][r]-prefix[len-1][l-1]+MOD)%MOD)%MOD;
        }
    }

    int res=0;
    for(int i=1;i<=n;++i){
        res=(res+dp[n][i])%MOD;
    }
    cout<<res<<endl;
return 0;
}