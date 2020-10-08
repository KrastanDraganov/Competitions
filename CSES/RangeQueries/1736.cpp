#include<iostream>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=2e5+3;
long long nums[MAXN],tree[4*MAXN],lazy[2][4*MAXN];

long long sum(int num){
    return (long long) num*(num+1)/2;
}

void push(int ind, int l, int r){
    if(lazy[0][ind]==0){
        return;
    }

    int mid=(l+r)/2;

    tree[2*ind]+=lazy[0][ind]*(sum(mid+1)-sum(l))-lazy[1][ind]*(mid-l+1);
    tree[2*ind+1]+=lazy[0][ind]*(sum(r+1)-sum(mid+1))-lazy[1][ind]*(r-mid);

    for(int i=0;i<2;++i){
        lazy[i][2*ind]+=lazy[i][ind];
        lazy[i][2*ind+1]+=lazy[i][ind];
        lazy[i][ind]=0;
    }
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
        ++lazy[0][ind];
        lazy[1][ind]+=startl;
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