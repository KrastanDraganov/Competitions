#include<iostream>
#include<cstring>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
pair<int,int> tree[4*MAXN];
int nums[MAXN],res[MAXN],lazy[4*MAXN];

void build_tree(int ind, int l, int r){
    if(l==r){
        tree[ind]={nums[l],l};
    }else{
        int mid=(l+r)/2;
        build_tree(2*ind,l,mid);
        build_tree(2*ind+1,mid+1,r);
        tree[ind]=min(tree[2*ind],tree[2*ind+1]);
    }
}

void fix(int curr){
    tree[2*curr].first+=lazy[curr];
    lazy[2*curr]+=lazy[curr];
    tree[2*curr+1].first+=lazy[curr];
    lazy[2*curr+1]+=lazy[curr];
    lazy[curr]=0;
}

void update(int ind, int tl, int tr, int l, int r, int add){
    if(l>r){
        return;
    }
    if(l==tl and r==tr){
        tree[ind].first+=add;
        if(l==r and tree[ind].first<0){
            tree[ind].first=1e9;
        }
        lazy[ind]+=add;
    }else{
        if(tl!=tr){
            fix(ind);
        }else{
            lazy[ind]=0;
        }
        int mid=(tl+tr)/2;
        update(2*ind,tl,mid,l,min(mid,r),add);
        update(2*ind+1,mid+1,tr,max(l,mid+1),r,add);
        tree[ind]=min(tree[2*ind],tree[2*ind+1]);
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
    
    memset(lazy,0,sizeof(lazy));
    build_tree(1,0,n-1);
    for(int i=n;i>=1;--i){
        cout<<tree[1].second<<endl;
        res[tree[1].second]=i;
        update(1,0,n-1,0,tree[1].second,-1);
    }
    
    for(int i=0;i<n;++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
return 0;
}