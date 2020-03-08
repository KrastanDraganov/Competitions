#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=103,MOD=1e6+1;
long long dp[MAXN][MAXN][MAXN];

long long sol(int x, int y, int counter){
    if(x<0 or y<0 or counter<0){
        return 0;
    }
    if(counter==0){
        return 1;
    }
    long long& ans=dp[x][y][counter];
    if(ans!=-1){
        return ans;
    }
    ans=0;
    ans=(ans+sol(x-1,y,counter))%MOD;
    ans=(ans+y*sol(x-1,y-1,counter-1))%MOD;
    ans=(ans+y*(x-1)*sol(x-2,y-1,counter-2))%MOD;
    ans=(ans+((y*(y-1))/2)*sol(x-1,y-2,counter-2))%MOD;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,y,n;
    cin>>x>>y>>n;
    memset(dp,-1,sizeof(dp));
    cout<<sol(x,y,n)<<endl;
return 0;
}