#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MOD=1e6,BORDER=1009;
int dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin>>k;
    
    dp[0]=2;
    dp[9]=2;
    
    int sum=0;
    for(int i=10;i<k;++i){
        if(i>=BORDER){
            sum-=dp[i-BORDER];
        }
        sum=sum+dp[i-10];
        sum%=MOD;
        dp[i]=sum;

    }
    cout<<dp[k-1]<<endl;
return 0;
}