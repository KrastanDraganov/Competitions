#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXK=1e5+3,MOD=1e9+7;
int dp[MAXK],prefix[MAXK];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    dp[0]=1;
    for(int i=0;i<n;++i){
        int limit;
        cin>>limit;
        memset(prefix,0,sizeof(prefix));
        for(int i2=k;i2>=0;--i2){
            int l=i2+1,r=i2+min(k-i2,limit);
            if(l<=r){
                prefix[l]=(prefix[l]+dp[i2])%MOD;
                if(r<k){
                    prefix[r+1]=(prefix[r+1]-dp[i2]+MOD)%MOD;
                }
            }
        }
        int sum=0;
        for(int i2=0;i2<=k;++i2){
            sum=(sum+prefix[i2])%MOD;
            dp[i2]=(dp[i2]+sum)%MOD;
        }
    }
    cout<<dp[k]<<endl;
return 0;
}