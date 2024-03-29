#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN = 1e5+3;
int tree[4*MAXN],lazy[4*MAXN];
void update(int ind, int cl, int cr, int l, int r, int add){
    if(cl>cr) return;
    if(lazy[ind]!=0){
        tree[ind]+=(cr-cl+1)*lazy[ind];
        if(cl!=cr){
            lazy[2*ind]+=lazy[ind];
            lazy[2*ind+1]+=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(cl>r or cr<l) return;
    if(cl==l and cr==r){
        tree[ind]+=add*(cr-cl+1);
        if(cr!=cl){
            lazy[2*ind]+=add;
            lazy[2*ind+1]+=add;
        }
        return;
    }
    int mid=(cl+cr)/2;
    update(2*ind,cl,mid,l,min(r,mid),add);
    update(2*ind+1,mid+1,cr,max(mid+1,l),r,add);
    tree[ind]=tree[2*ind]+tree[2*ind+1];
}
int query(int ind, int cl, int cr, int l, int r){
    if(cl>cr or cl>r or cr<l){ 
        return 0;
    }
    if(lazy[ind]!=0){
        tree[ind]+=(cr-cl+1)*lazy[ind];
        if(cl!=cr){
            lazy[2*ind]+=lazy[ind];
            lazy[2*ind+1]+=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(cl==l and cr==r){
        return tree[ind];
    }
    int mid=(cl+cr)/2;
    return query(2*ind,cl,mid,l,min(mid,r))+query(2*ind+1,mid+1,cr,max(mid+1,l),r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int test=0;test<t;++test){
        int n,c;
        cin>>n>>c;
        for(int i=1;i<=4*n;++i){
            tree[i]=0;
            lazy[i]=0;
        }
        for(int i=0;i<c;++i){
            int type,l,r;
            cin>>type>>l>>r;
            --l;
            --r;
            if(type==0){
                int x;
                cin>>x;
                update(1,0,n-1,l,r,x);
            }else{
                cout<<query(1,0,n-1,l,r)<<endl;
            }
        }
    }
return 0;
}