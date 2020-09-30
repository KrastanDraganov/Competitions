#include<iostream>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=2e5+3,MAXL=31;
int prelog2[MAXN],st[MAXN][MAXL];
 
void calc_sparse_table(int n){
    prelog2[1]=0;
    for(int i=2;i<MAXN;++i){
        prelog2[i]=prelog2[i/2]+1;
    }
 
    for(int range=1;range<MAXL;++range){
        for(int i=0;i+(1<<range)<=n;++i){
            st[i][range]=min(st[i][range-1],st[i+(1<<(range-1))][range-1]);
        }
    }
}
 
int min_query(int l, int r){
    --l;
    --r;
    int range=prelog2[r-l+1];
    return min(st[l][range],st[r-(1<<range)+1][range]);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,q;
    cin>>n>>q;
 
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        st[i][0]=num;
    }
 
    calc_sparse_table(n);
 
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<min_query(l,r)<<endl;
    }
return 0;
}