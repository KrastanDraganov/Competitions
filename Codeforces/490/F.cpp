#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=503,MAXK=13,MAXC=1e5+3;
int joy[MAXK],players[MAXC],cards[MAXC],dp[MAXN][MAXC];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<k*n;++i){
        int curr;
        cin>>curr;
        ++cards[curr];
    }
    for(int i=0;i<n;++i){
        int fav;
        cin>>fav;
        ++players[fav];
    }
    for(int i=1;i<=k;++i){
        cin>>joy[i];
    }

    for(int i=0;i<n;++i){
        for(int i2=0;i2<=n*k;++i2){
            for(int cnt=0;cnt<=k and i2+cnt<=n*k;++cnt){
                dp[i+1][i2+cnt]=max(dp[i+1][i2+cnt],dp[i][i2]+joy[cnt]);
            }
        }
    }

    int res=0;
    for(int i=0;i<MAXC;++i){
        res+=dp[players[i]][cards[i]];
    }
    cout<<res<<endl;
return 0;
}
