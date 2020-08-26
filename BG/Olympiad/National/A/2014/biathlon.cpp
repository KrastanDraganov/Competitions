//Only 75/100 points

#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int passed[MAXN],lazy[4*MAXN];
pair<int,int> tree[4*MAXN];

void build(int ind, int tl, int tr){
    if(tl==tr){
        tree[ind]={passed[tl],tl};
    }else{
        int mid=(tl+tr)/2;
        build(2*ind,tl,mid);
        build(2*ind+1,mid+1,tr);
        tree[ind]=min(tree[2*ind],tree[2*ind+1]);
    }
}

void push(int ind){
    tree[2*ind].first+=lazy[ind];
    lazy[2*ind]+=lazy[ind];
    tree[2*ind+1].first+=lazy[ind];
    lazy[2*ind+1]+=lazy[ind];
    lazy[ind]=0;
}

void update_pos(int ind, int tl, int tr, int pos){
    if(tl>tr or pos<tl or pos>tr){
        return;
    }
    if(tl==tr){
        tree[ind].first=1e9;
    }else{
        push(ind);
        int mid=(tl+tr)/2;
        if(pos<=mid){
            update_pos(2*ind,tl,mid,pos);
        }else{
            update_pos(2*ind+1,mid+1,tr,pos);
        }
        tree[ind]=min(tree[2*ind],tree[2*ind+1]);
    }
}

void update_range(int ind, int tl, int tr, int l, int r, int val){
    if(l>tr or r<tl or l>r){
        return;
    }
    if(l==tl and r==tr){
        tree[ind].first+=val;
        lazy[ind]+=val;
    }else{
        if(tl!=tr){
            push(ind);
        }else{
            lazy[ind]=0;
        }
        int mid=(tl+tr)/2;
        update_range(2*ind,tl,mid,l,min(mid,r),val);
        update_range(2*ind+1,mid+1,tr,max(mid+1,l),r,val);
        tree[ind]=min(tree[2*ind],tree[2*ind+1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>passed[i];
    }

    build(1,0,n-1);
    for(int i=0;i<n;++i){
        int curr=tree[1].second;
        cout<<curr+1<<endl;
        update_pos(1,0,n-1,curr);
        update_range(1,0,n-1,0,curr-1,-1);
    }
return 0;
}