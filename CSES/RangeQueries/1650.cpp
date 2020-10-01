#include<iostream>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=2e5+3;
int prefix[MAXN];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,q;
    cin>>n>>q;
 
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        prefix[i+1]=prefix[i]^num;
    }
 
    while(q--){
        int l,r;
        cin>>l>>r;
 
        int res=prefix[r]^prefix[l-1];
        cout<<res<<endl;
    }
return 0;
}