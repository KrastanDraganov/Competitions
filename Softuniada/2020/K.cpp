#include<iostream>
#define endl '\n'
using namespace std;
const int MOD=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,d,l,u;
    cin>>n>>d>>l>>u;
    if(d+l+u>n){
        cout<<0<<endl;
    }else if(d==l and d==u){
        long long res=1;
        for(long long i=2;i<=n;++i){
            res=(res*i)%MOD;
        }
        res=(res*9000)%MOD;
        cout<<res<<endl;
    }
return 0;
}