#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXS=1e4+3,MAXD=103,MOD=1e9+7;

int dp[MAXS][MAXD][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int d;
    cin>>s>>d;
    int n=s.size();

    dp[0][0][0]=1;
    for(int pos=0;pos<n;++pos){
        int curr=s[pos]-'0';
        for(int sum=0;sum<d;++sum){
            for(int smaller=0;smaller<2;++smaller){
                for(int digit=0;digit<10;++digit){
                    if(digit>curr and !smaller){
                        break;
                    }
                    dp[pos+1][(sum+digit)%d][smaller or (digit<curr)]=(dp[pos+1][(sum+digit)%d][smaller or (digit<curr)]+dp[pos][sum][smaller])%MOD;
                }
            }
        }
    }

    int res=(dp[n][0][0]+dp[n][0][1])%MOD;
    --res;
    cout<<(res==-1 ? MOD-1 : res)<<endl;

return 0;
}