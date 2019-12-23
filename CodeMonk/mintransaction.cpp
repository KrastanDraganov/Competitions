#include<iostream>
#define endl '\n'
#define MAXN (int)1e5+2
using namespace std;
long long money[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int v,u,w;
        cin>>v>>u>>w;
        money[v]+=w;
        money[u]-=w;
    }
    long long res=0;
    for(int i=1;i<=n;++i){
        if(money[i]>0){
            res+=money[i];
        }
    }
    cout<<res<<endl;
return 0;
}