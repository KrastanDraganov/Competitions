#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=3e3+3;
int table[MAXN][MAXN],prefix[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,u,v;
    cin>>n>>m>>u>>v;
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=m;++i2){
            cin>>table[i][i2];
            prefix[i][i2]=prefix[i-1][i2]+prefix[i][i2-1]-prefix[i-1][i2-1]+table[i][i2];
        }
    }

    int res=1e9;
    for(int i=u;i<=n;++i){
        for(int i2=v;i2<=m;++i2){
            int curr=prefix[i][i2]-prefix[i][i2-v]-prefix[i-u][i2]+prefix[i-u][i2-v];
            res=min(res,abs(curr));
        }
    }
    cout<<res<<endl;
return 0;
}