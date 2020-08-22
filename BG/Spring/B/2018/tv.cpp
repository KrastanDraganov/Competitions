#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN = 5e5+3;
int nums[MAXN],tree[4*MAXN],lazy[4*MAXN],change_ind[MAXN];

void build(int ind, int l, int r){
    if(l==r){
        tree[ind]=nums[r];
    }else{
        int mid=(l+r)/2;
        build(2*ind,l,mid);
        build(2*ind+1,mid+1,r);
        tree[ind]=tree[2*ind]+tree[2*ind+1];
    }
}

void push_down(int ind, int l, int r){
    if(lazy[ind]==-1 and l!=r){
        lazy[2*ind]=(-1)*lazy[2*ind];
        lazy[2*ind+1]=(-1)*lazy[2*ind+1];
        lazy[ind]=1;
    }
}

void update(int ind, int cl, int cr, int l, int r){
    if(l>r or l>cr or cl>r){
        return;
    }
    if(cl==l and cr==r){
        lazy[ind]=(-1)*lazy[ind];
        return;
    }
    push_down(ind,cl,cr);
    int mid=(cl+cr)/2;
    update(2*ind,cl,mid,l,min(r,mid));
    update(2*ind+1,mid+1,cr,max(l,mid+1),r);
    tree[ind]=lazy[2*ind]*tree[2*ind]+lazy[2*ind+1]*tree[2*ind+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,q;
    string s;
    cin>>n>>q>>s;
    
    int last=0;
    for(int i=0;i<s.size();++i){
        int curr=(-1)*last;
        switch(s[i]){
            case '+' : curr=1; break;
            case '-' : curr=-1; break;
            default : break;
        }
        nums[i]=curr;
        last=curr;
    }
    
    last=(int)s.size();
    for(int i=s.size()-1;i>=0;--i){
        if(s[i]!='o'){
            last=i;
        }
        change_ind[i]=last;
    }
    
    change_ind[(int)s.size()]=(int)s.size();
    for(int i=0;i<4*MAXN;++i){
        lazy[i]=1;
    }
    build(1,0,s.size()-1);
    
    for(int i=0;i<q;++i){
        int l,r;
        cin>>l>>r;
        --l;
        --r;
        l=change_ind[l];
        r=change_ind[r+1]-1;
        update(1,0,s.size()-1,l,r);
        int ans=(1+lazy[1]*tree[1])%n;
        cout<<(ans<=0 ? ans+n : ans)<<endl;
    }
return 0;
}