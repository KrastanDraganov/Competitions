#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int nums[MAXN],tree[4*MAXN];

void build_tree(int ind, int l, int r){
    if(l==r){
        tree[ind]=1;
        return;
    }

    int mid=(l+r)/2;
    build_tree(2*ind, l, mid);
    build_tree(2*ind+1, mid+1, r);

    tree[ind]=tree[2*ind]+tree[2*ind+1];
}

void update_tree(int ind, int l, int r, int target){
    if(l==r){
        tree[ind]=0;
        return;
    }

    int mid=(l+r)/2;
    if(target<=mid){
        update_tree(2*ind, l, mid, target);
    }else{
        update_tree(2*ind+1, mid+1, r, target);
    }

    tree[ind]=tree[2*ind]+tree[2*ind+1];
}

int query(int ind, int l, int r, int counter){
    if(l==r){
        return l;
    }

    int mid=(l+r)/2;
    if(tree[2*ind]>=counter){
        return query(2*ind, l, mid, counter);
    }else{
        return query(2*ind+1, mid+1, r, counter-tree[2*ind]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    build_tree(1, 0, n-1);

    for(int i=0;i<n;++i){
        int pos;
        cin>>pos;

        int res=query(1, 0, n-1, pos);
        cout<<nums[res]<<" ";
        update_tree(1, 0, n-1, res);
    }
    cout<<endl;
return 0;
}