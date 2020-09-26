#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    for(int num=1;num<=n;++num){
        dp[num]=MAXN;
        for(char curr : to_string(num)){
            int digit=curr-'0';
            if(digit<=num){
                dp[num]=min(dp[num],dp[num-digit]+1);
            }
        }
    }

    cout<<dp[n]<<endl;
return 0;
}