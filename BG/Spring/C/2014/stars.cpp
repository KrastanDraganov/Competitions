#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=25e3+3;
int dp[2][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,t;
    cin>>n>>m>>t;
    
    int res=(n%2);
    for(int i=0;i<=n;++i){
        int curr=i%2,prev=(i-1)%2;
        dp[curr][0]=1;
        for(int i2=1;i2<=i;++i2){
            dp[curr][i2]=(dp[prev][i2]+dp[prev][i2-1])%m;
        }
    }
    for(int i=0;i<=n;++i){
        dp[res][i]+=dp[res][i-1];
    }

    while(t--){
        int l,r;
        cin>>l>>r;
        int curr=dp[res][r]-dp[res][l-1];
        cout<<(curr%m==0 ? m : curr%m)<<" ";
    }
    cout<<endl;
return 0;
}