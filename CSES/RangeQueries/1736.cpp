// Not solved - wrong answer

#include<iostream>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=2e5+3;
long long nums[MAXN],tree[4*MAXN],lazy[4*MAXN];

long long sum(int num){
    return (long long) num*(num+1)/2;
}

void push(int ind, int l, int r){
    if(lazy[ind]==-1){
        return;
    }

    int mid=(l+r)/2;

    int addl=l-lazy[ind]+1;
    int addr=mid-lazy[ind]+1;
    tree[2*ind]+=sum(addr)-sum(addl-1);

    addl=mid+1-lazy[ind]+1;
    addr=r-lazy[ind]+1;
    tree[2*ind+1]+=sum(addr)-sum(addl-1);

    lazy[2*ind]=lazy[2*ind+1]=lazy[ind];
    lazy[ind]=-1;
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
 
void update_tree(int ind, int tl, int tr, int l, int r, int startl){
    if(l>tr or r<tl or l>r){
        return;
    }
 
    if(l==tl and r==tr){
        int addl=l-startl+1;
        int addr=r-startl+1;
        tree[ind]+=sum(addr)-sum(addl-1);
        lazy[ind]=startl;
        return;
    }
 
    push(ind, tl, tr);
 
    int mid=(tl+tr)/2;
    update_tree(2*ind, tl, mid, l, min(mid, r), startl);
    update_tree(2*ind+1, mid+1, tr, max(mid+1, l), r, startl);
 
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
    
    for(int i=0;i<4*n;++i){
        lazy[i]=-1;
    }

    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    build_tree(1, 0, n-1);
 
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        --l;
        --r;
 
        if(type==2){
            cout<<query(1, 0, n-1, l, r)<<endl;
        }else{
            update_tree(1, 0, n-1, l, r, l);
        }
    }
return 0;
}