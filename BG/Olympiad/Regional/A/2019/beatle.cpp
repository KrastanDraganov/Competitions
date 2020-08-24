#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN = 1e5+3;

pair<int,pair<int,int>> cord[MAXN];
int tree[4*MAXN],lazy[4*MAXN];

int query(int ind, int l, int r, int search_ind){
    if(l>r){
        return 0;
    }
    if(lazy[ind]!=0){
        return lazy[ind];
    }
    if(l==r){
        return tree[ind];
    }
    int mid=(l+r)/2;
    return (search_ind<=mid ? query(2*ind,l,mid,search_ind) : query(2*ind+1,mid+1,r,search_ind));
}

void update(int ind, int cl, int cr, int l, int r, int change){
    if(l>r or cl>r or cr<l){
        return;
    }
    if(cl==l and cr==r){
        tree[ind]=change;
        lazy[ind]=change;
    }else{
        if(lazy[ind]!=0){
            if(cl!=cr){
                lazy[2*ind]=lazy[ind];
                lazy[2*ind+1]=lazy[ind];
            }
            lazy[ind]=0;
        }
        int mid=(cl+cr)/2;
        update(2*ind,cl,mid,l,min(mid,r),change);
        update(2*ind+1,mid+1,cr,max(mid+1,l),r,change);
        tree[ind]=min(tree[2*ind],tree[2*ind+1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x,y,d;
        cin>>x>>y>>d;
        cord[i]={y,{x,d}};
    }
    sort(cord,cord+n);
    
    for(pair<int,pair<int,int>> curr : cord){
        int l=curr.second.first,r=curr.second.second+l;
        int ans=min(query(1,1,MAXN,l),query(1,1,MAXN,r+1))+1;
        update(1,1,MAXN,l+1,r,ans);
    }
    
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        int x;
        cin>>x;
        cout<<query(1,1,MAXN,x+1)<<" ";
    }
    cout<<endl;
return 0;
}