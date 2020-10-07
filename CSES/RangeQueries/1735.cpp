#include<iostream>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=2e5+3;
long long nums[MAXN],tree[4*MAXN],lazy[2][4*MAXN];
 
void push(int ind, int l, int r){
    int mid=(l+r)/2;
 
    if(lazy[1][ind]>0){
        tree[2*ind]=(mid-l+1)*lazy[1][ind];
        tree[2*ind+1]=(r-mid)*lazy[1][ind];
        lazy[1][2*ind]=lazy[1][2*ind+1]=lazy[1][ind];
        lazy[0][2*ind]=lazy[0][2*ind+1]=0;
    }
 
    tree[2*ind]+=(mid-l+1)*lazy[0][ind];
    tree[2*ind+1]+=(r-mid)*lazy[0][ind];
    lazy[0][2*ind]+=lazy[0][ind];
    lazy[0][2*ind+1]+=lazy[0][ind];
 
    lazy[0][ind]=lazy[1][ind]=0;
}
 
void build_tree(int ind, int tl, int tr){
    if(tl==tr){
        tree[ind]=nums[tl];
        return;
    }
 
    int mid=(tl+tr)/2;
    build_tree(2*ind, tl, mid);
    build_tree(2*ind+1, mid+1, tr);
 
    tree[ind]=tree[2*ind]+tree[2*ind+1];
}
 
void update_tree(int ind, int tl, int tr, int l, int r, long long val, int type){
    if(l>tr or r<tl or l>r){
        return;
    }
 
    if(l==tl and r==tr){
        if(type==1){
            tree[ind]=val*(r-l+1);
            lazy[type][ind]=val;
            lazy[type-1][ind]=0;
        }else{
            tree[ind]+=val*(r-l+1);
            lazy[type][ind]+=val;
        }
        return;
    }
 
    push(ind, tl, tr);
 
    int mid=(tl+tr)/2;
    update_tree(2*ind, tl, mid, l, min(mid, r), val, type);
    update_tree(2*ind+1, mid+1, tr, max(mid+1, l), r, val, type);
 
    tree[ind]=tree[2*ind]+tree[2*ind+1];
}
 
long long query(int ind, int tl, int tr, int l, int r){
    if(l>tr or r<tl or l>r){
        return 0;
    }
 
    if(tl==l and tr==r){
        return tree[ind];
    }
 
    push(ind, tl, tr);
 
    int mid=(tl+tr)/2;
    return query(2*ind, tl, mid, l, min(mid, r))
        +query(2*ind+1, mid+1, tr, max(mid+1, l), r);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,q;
    cin>>n>>q;
 
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    build_tree(1, 0, n-1);
 
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        --l;
        --r;
 
        if(type==3){
            cout<<query(1, 0, n-1, l, r)<<endl;
        }else{
            long long val;
            cin>>val;
            update_tree(1, 0, n-1, l, r, val, type-1);
        }
    }
return 0;
}