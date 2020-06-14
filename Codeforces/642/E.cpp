#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int prefix[MAXN],dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,k;
        string lamps;
        cin>>n>>k>>lamps;
        for(int i=1;i<=n;++i){
            prefix[i]=prefix[i-1]+(lamps[i-1]=='1');
        }
        
        int res=prefix[n];
        for(int i=1;i<=n;++i){
            bool is_turned=(lamps[i-1]!='1');
            if(i-k>0){
                dp[i]=min(prefix[i-1],dp[i-k]+prefix[i-1]-prefix[i-k])+is_turned;
            }else{
                dp[i]=prefix[i-1]+is_turned;
            }
            res=min(res,dp[i]+prefix[n]-prefix[i]);
        }
        cout<<res<<endl;
    }
return 0;
}