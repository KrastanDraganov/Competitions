#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;

struct tree_data {
    int length,l,r,prefix,suffix,ans;
};

tree_data tree[4*MAXN];
int lazy[4*MAXN];

tree_data init(){
    tree_data res;
    res.length=1;
    res.l=0;
    res.r=0;
    res.prefix=1;
    res.suffix=1;
    res.ans=1;
    return res;
}

tree_data combine(tree_data child1, tree_data child2){
    tree_data res;
    res.length=child1.length+child2.length;
    res.l=child1.l; 
    res.r=child2.r; 
    res.prefix=child1.prefix; 
    res.suffix=child2.suffix; 
    res.ans=max(child1.ans,child2.ans); 
    if(child1.r+child2.l==1){
        if(child1.length==child1.ans){
            res.prefix=max(res.prefix,child1.ans+child2.prefix);
        }
        if(child2.length==child2.ans){
            res.suffix=max(res.suffix,child2.ans+child1.suffix);
        }
        res.ans=max(res.ans,child1.suffix+child2.prefix); 
    }
    return res;
}

void change(int ind){
    tree[ind].l=!tree[ind].l;
    tree[ind].r=!tree[ind].r;
}

void push(int ind){
    change(2*ind);
    change(2*ind+1);
    lazy[ind]=1;
}

void build(int ind, int tl, int tr){
    if(tl==tr){
        tree[ind]=init();
    }else{
        int mid=(tl+tr)/2;
        build(2*ind,tl,mid);
        build(2*ind+1,mid+1,tr);
        tree[ind]=combine(tree[2*ind],tree[2*ind+1]);
    }
}

void update(int ind, int tl, int tr, int l, int r, int val){
    if(r<tl or l>tr or l>r){
        return;
    }
    if(tl==l and tr==r){
        //cout<<"change: "<<l<<" "<<r<<endl;
        change(ind);
        lazy[ind]*=val;
    }else{
        if(lazy[ind]!=1){
            push(ind);
        }
        int mid=(tl+tr)/2;
        update(2*ind,tl,mid,l,min(mid,r),val);
        update(2*ind+1,mid+1,tr,max(mid+1,l),r,val);
        tree[ind]=combine(tree[2*ind],tree[2*ind+1]);
        //cout<<tl<<" "<<tr<<" "<<tree[ind].ans<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0;i<4*MAXN;++i){
        lazy[i]=1;
    }

    int n,q;
    cin>>n>>q;
    
    build(1,0,n-1);
    while(q--){
        char type;
        cin>>type;
        if(type=='q'){
            cout<<tree[1].ans<<endl;
        }else{
            int l,r;
            cin>>l>>r;
            update(1,0,n-1,l,r,-1);
            //cout<<tree[1].ans<<endl;
        }
    }
return 0;
}
