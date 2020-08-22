#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3;
int field[MAXN][MAXN],sum[MAXN][MAXN];

int calc(int i, int i2, int m, int k, int n){
    if(i+m-1>n or i2+m-1>n){
        return k;
    }
    return sum[i+m-1][i2+m-1]+sum[i-1][i2-1]-sum[i-1][i2+m-1]-sum[i+m-1][i2-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=n;++i2){
            cin>>field[i][i2];
            sum[i][i2]=sum[i][i2-1]+sum[i-1][i2]-sum[i-1][i2-1]+field[i][i2];
        }
    }
    
    int res=1;
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=n;++i2){
            while(calc(i,i2,res,k,n)<k){
                ++res;
            }
        }
    }
    cout<<(res==n+1 ? -1 : res)<<endl;
return 0;
}