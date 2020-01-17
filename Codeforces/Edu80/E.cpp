#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN=6e5+3;
int sent[MAXN],pos[MAXN],fenwick[MAXN],min_msg[MAXN],max_msg[MAXN];
void update(int ind, int val){
    while(ind<MAXN){
        fenwick[ind]+=val;
        ind+=(ind & (-ind));
    }
}
int query(int ind){
    int res=0;
    while(ind>0){
        res+=fenwick[ind];
        ind-=(ind & (-ind));
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        min_msg[i]=max_msg[i]=i;
        pos[i]=m+i;
        update(pos[i],1);
    }
    for(int i=1;i<=m;++i){
        cin>>sent[i];
        min_msg[sent[i]]=1;
    }
    for(int i=1;i<=m;++i){
        max_msg[sent[i]]=max(max_msg[sent[i]],query(pos[sent[i]]));
        update(pos[sent[i]],-1);
        pos[sent[i]]=m-i+1;
        update(pos[sent[i]],1);
    }
    for(int i=1;i<=n;++i){
        max_msg[i]=max(max_msg[i],query(pos[i]));
        cout<<min_msg[i]<<" "<<max_msg[i]<<endl;
    }
return 0;
}
