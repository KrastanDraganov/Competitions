#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3,MOD=1e9+7;
long long x[MAXN],y[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x[i]>>y[i];
    }

    sort(x,x+n);
    sort(y,y+n);
    long long sumx=x[0],sumy=y[0],res=0;
    for(int i=1;i<n;++i){
        res=(res+i*(x[i]+y[i])-sumx-sumy)%MOD;
        sumx=(sumx+x[i])%MOD;
        sumy=(sumy+y[i])%MOD;
    }
    cout<<res<<endl;
return 0;
}