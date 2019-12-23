#include<iostream>
#define endl '\n'
#define MAXN 1003
using namespace std;
int sum[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=m;++i2){
            cin>>sum[i][i2];
            sum[i][i2]+=sum[i-1][i2]+sum[i][i2-1]-sum[i-1][i2-1];
        }
    }
    int res=0;
    for(int i=k;i<=n;++i){
        for(int i2=k;i2<=m;++i2){
            res=max(res,sum[i][i2]+sum[i-k][i2-k]-sum[i-k][i2]-sum[i][i2-k]);
        }
    }
    cout<<sum[n][m]-res<<endl;
return 0;
}