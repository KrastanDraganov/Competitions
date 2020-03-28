#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int height[MAXN];
long long beauty[MAXN],dp[MAXN],tree[4*MAXN];

void update(int ind, int tl, int tr, int pos, long long val){
    if(tl==tr){
        tree[ind]=val;
    }else{
        int mid=(tl+tr)/2;
        if(pos<=mid){
            update(2*ind,tl,mid,pos,val);
        }else{
            update(2*ind+1,mid+1,tr,pos,val);
        }
        tree[ind]=max(tree[2*ind],tree[2*ind+1]);
    }
}

long long get_max(int ind, int tl, int tr, int l, int r){
    if(l>r){
        return -1e18;
    }
    if(tl==l and tr==r){
        return tree[ind];
    }
    int mid=(tl+tr)/2;
    return max(get_max(2*ind,tl,mid,l,min(mid,r)),get_max(2*ind+1,mid+1,tr,max(l,mid+1),r));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>height[i];
    }
    for(int i=0;i<n;++i){
        cin>>beauty[i];
    }

    for(int i=0;i<n;++i){
        long long prev=get_max(1,0,n,0,height[i]);
        dp[height[i]]=prev+beauty[i];
        update(1,0,n,height[i],dp[height[i]]);
    }

    long long res=0;
    for(int i=0;i<n;++i){
        res=max(res,dp[height[i]]);
    }
    cout<<res<<endl;
return 0;
}