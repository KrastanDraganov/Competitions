#include<iostream>
#include<algorithm>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=25e4+3,MOD=1e9+7;
int apex[MAXN],dp[MAXN];

int sol(int i, int n, int m){
    int& res=dp[i];
    if(dp[i]!=-1){ 
        return dp[i];
    }
    
    int nexti=i+1,nexti2=i+2;
    if(apex[nexti]==apex[i]){
        for(int j=i+2;j<=n*m;j++){
            if(j==n*m){ 
                return 1;
            }
            if(apex[j]>apex[i]){
                nexti=j;
                break;
            }
        }
        nexti2=nexti+1;
        if(nexti2==n*m){ 
            return 1;
        }
    }
    
    if(nexti==n*m or nexti2==n*m){ 
        return 1;
    }
    
    res=(sol(nexti,n,m)+sol(nexti2,n,m))%MOD;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>apex[i];
    }
    sort(apex,apex+n*m);

    memset(dp,-1,sizeof(dp));
    cout<<sol(0,n,m)<<endl;
return 0;
}