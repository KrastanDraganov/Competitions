#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+4;
int hotels[MAXN],tree[4*MAXN];

void build_tree(int ind, int l, int r){
    if(l==r){
        tree[ind]=hotels[l];
        return;
    }

    int mid=(l+r)/2;
    build_tree(2*ind, l, mid);
    build_tree(2*ind+1, mid+1, r);

    tree[ind]=max(tree[2*ind], tree[2*ind+1]);
}

void update_tree(int ind, int l, int r, int target){
    if(l==r){
        tree[ind]=hotels[l];
        return;
    }

    int mid=(l+r)/2;
    if(target<=mid){
        update_tree(2*ind, l, mid, target);
    }else{
        update_tree(2*ind+1, mid+1, r, target);
    }

    tree[ind]=max(tree[2*ind], tree[2*ind+1]);
}

int query(int ind, int l, int r, int min_rooms){
    if(tree[ind]<min_rooms){
        return 0;
    }

    if(l==r){
        return l+1;
    }

    int mid=(l+r)/2;
    if(tree[2*ind]>=min_rooms){
        return query(2*ind, l, mid, min_rooms);
    }else{
        return query(2*ind+1, mid+1, r, min_rooms);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        cin>>hotels[i];
    }

    build_tree(1,0,n-1);

    while(m--){
        int guests;
        cin>>guests;

        int res=query(1, 0, n-1, guests);
        cout<<res<<" ";

        if(res>0){
            hotels[res-1]-=guests;
            update_tree(1, 0, n-1, res-1);
        }
    }
    cout<<endl;
return 0;
}