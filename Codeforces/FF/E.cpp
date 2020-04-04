#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=3e5+3,MOD=1e9+9;
long long fibonacci[MAXN],tree[4*MAXN],nums[MAXN],lazy[4*MAXN];

void build(int ind, int tl, int tr){
    if(tl==tr){
        tree[ind]=nums[tl];
    }else{
        int mid=(tl+tr)/2;
        build(2*ind,tl,mid);
        build(2*ind+1,mid+1,tr);
        tree[ind]=(tree[2*ind]+tree[2*ind+1])%MOD;
    }
}

void add_self(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

void push(int ind, int l, int r){
    int mid=(l+r)/2;
    add_self(tree[2*ind],lazy[ind]*);
    add_self(tree[2*ind+1],lazy[ind]*);
    add_self(lazy[2*ind],lazy[ind]*);
    add_self(lazy[2*ind+1],lazy[ind]*);
    lazy[ind]=0;
}

void update(int ind, int tl, int tr, int l, int r, int val){
    if(l>tr or r<tl or l>r){
        return;
    }
    if(tl==l and tr==r){
        add_self(tree[ind],);
        if(tl!=tr){
            ++lazy[ind];
        }
    }else{
        push(ind,tl,tr);
        int mid=(tl+tr)/2;
        update(2*ind,tl,mid,l,min(r,mid),val);
        update(2*ind+1,mid+1,tr,max(mid+1,l),r,val);
        tree[ind]=(tree[2*ind]+tree[2*ind+1])%MOD;
    }
}

long long query(int ind, int tl, int tr, int l, int r){
    if(l>tr or r<tl or l>r){
        return 0;
    }
    if(tl==l and tr==r){
        return tree[ind];
    }
    push(ind,tl,tr);
    int mid=(tl+tr)/2;
    return (query(2*ind,tl,mid,l,min(mid,r))+query(2*ind+1,mid+1,tr,max(mid+1,l),r))%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    build(1,0,n-1);

    fibonacci[1]=1;
    prefix[1]=1;
    for(int i=2;i<=n;++i){
        fibonacci[i]=(fibonacci[i-1]+fibonacci[i-2])%MOD;
        prefix[i]=(prefix[i-1]+fibonacci[i])%MOD;
    }

    for(int i=0;i<m;++i){
        int type,l,r;
        cin>>type>>l>>r;
        --l;
        --r;
        if(type==1){
            update(1,0,n-1,l,r,l);
        }else{
            cout<<query(1,0,n-1,l,r)<<endl;
        }
    }
return 0;
}