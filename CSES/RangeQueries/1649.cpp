#include<iostream>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=2e5+3;
int nums[MAXN],tree[4*MAXN];
 
void build_tree(int ind, int tl, int tr){
    if(tl==tr){
        tree[ind]=nums[tl];
        return;
    }
 
    int mid=(tl+tr)/2;
    build_tree(2*ind, tl, mid);
    build_tree(2*ind+1, mid+1, tr);
 
    tree[ind]=min(tree[2*ind], tree[2*ind+1]);
}
 
void update(int ind, int tl, int tr, int target){
    if(tl==tr){
        tree[ind]=nums[target];
        return;
    }
 
    int mid=(tl+tr)/2;
    if(target<=mid){
        update(2*ind, tl, mid, target);
    }else{
        update(2*ind+1, mid+1, tr, target);
    }
 
    tree[ind]=min(tree[2*ind], tree[2*ind+1]);
}
 
int query(int ind, int tl, int tr, int l, int r){
    if(l>tr or r<tl){
        return 1e9+3;
    }
 
    if(tl==l and tr==r){
        return tree[ind];
    }
 
    int mid=(tl+tr)/2;
    return min(query(2*ind, tl, mid, l, min(mid,r)),
               query(2*ind+1, mid+1, tr, max(mid+1,l), r));
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,q;
    cin>>n>>q;
 
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
 
    build_tree(1,0,n-1);
 
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
 
        if(type==2){
            cout<<query(1, 0, n-1, l-1, r-1)<<endl;
        }else{
            nums[l-1]=r;
            update(1, 0, n-1, l-1);
        }
    }
return 0;
}