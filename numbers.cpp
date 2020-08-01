#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int nums[MAXN];

struct Query {
     int num,counter,gcd;
    
    Query(){
        num=1e9;
        counter=0;
        gcd=0;
    }
} tree[4*MAXN];

void build_tree(int ind, int tl, int tr){
    if(tl==tr){
        tree[ind].num=tree[ind].gcd=nums[tl];
        tree[ind].counter=1;
        return;
    }
    int mid=(tl+tr)/2;
    build_tree(2*ind,tl,mid);
    build_tree(2*ind+1,mid+1,tr);
    tree[ind].num=min(tree[2*ind].num,tree[2*ind+1].num);
    tree[ind].gcd=__gcd(tree[2*ind].gcd,tree[2*ind+1].gcd);
    if(tree[2*ind].num>tree[2*ind+1].num){
        tree[ind].counter=tree[2*ind+1].counter;
    }else if(tree[2*ind].num<tree[2*ind+1].num){
        tree[ind].counter=tree[2*ind].counter;
    }else{
        tree[ind].counter=tree[2*ind].counter+tree[2*ind+1].counter;
    }
}

void calc_res(int ind, int tl, int tr, int l, int r, Query& res){
    if(r<tl or l>tr){
        return;
    }
    if(l==tl and r==tr){
        if(tree[ind].num<res.num){
            res.counter=tree[ind].counter;
        }else if(tree[ind].num==res.num){
            res.counter+=tree[ind].counter;
        }
        res.num=min(res.num,tree[ind].num);
        res.gcd=__gcd(res.gcd,tree[ind].gcd);
        return;
    }
    int mid=(tl+tr)/2;
    calc_res(2*ind,tl,mid,l,min(mid,r),res);
    calc_res(2*ind+1,mid+1,tr,max(mid+1,l),r,res);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    build_tree(1,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        --l;
        --r;
        Query res;
        calc_res(1,0,n-1,l,r,res);
        cout<<res.num<<" "<<res.counter<<" "<<res.gcd<<endl;
    }
return 0;
}