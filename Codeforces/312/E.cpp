#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,ALPHABET=29;
int tree[4*MAXN][ALPHABET],lazy[4*MAXN][ALPHABET],counter[ALPHABET];
char s[MAXN],res[MAXN];

void build_tree(int ind, int tl, int tr){
    if(tl==tr){
        int curr=s[tl]-'a';
        tree[ind][curr]=1;
        for(int i=0;i<26;++i){
            lazy[ind][i]=-1;
        }
    }else{
        int mid=(tl+tr)/2;
        build_tree(2*ind,tl,mid);
        build_tree(2*ind+1,mid+1,tr);
        for(int i=0;i<26;++i){
            lazy[ind][i]=-1;
            tree[ind][i]=tree[2*ind][i]+tree[2*ind+1][i];
        }
    }
}

void push(int ind, int type, int l, int r){
    int mid=(l+r)/2;
    
    tree[2*ind][type]=(mid-l+1)*lazy[ind][type];
    lazy[2*ind][type]=lazy[ind][type];
    
    tree[2*ind+1][type]=(r-mid)*lazy[ind][type];
    lazy[2*ind+1][type]=lazy[ind][type];
    
    lazy[ind][type]=-1;
}

void update_range(int ind, int tl, int tr, int l, int r, int type, int val){
    if(l>tr or r<tl or l>r){
        return;
    }
    if(tl==l and tr==r){
        tree[ind][type]=(r-l+1)*val;
        lazy[ind][type]=val;
    }else{
        if(tl!=tr and lazy[ind][type]!=-1){
            push(ind,type,tl,tr);
        }else{
            lazy[ind][type]=-1;
        }
        int mid=(tl+tr)/2;
        update_range(2*ind,tl,mid,l,min(mid,r),type,val);
        update_range(2*ind+1,mid+1,tr,max(mid+1,l),r,type,val);
        tree[ind][type]=tree[2*ind][type]+tree[2*ind+1][type];
    }
}

int query(int ind, int tl, int tr, int l, int r, int type){
    if(l>tr or r<tl or l>r){
        return 0;
    }
    if(tl==l and tr==r){
        return tree[ind][type];
    }
    if(tl!=tr and lazy[ind][type]!=-1){
        push(ind,type,tl,tr);
    }else{
        lazy[ind][type]=-1;
    }
    int mid=(tl+tr)/2;
    return query(2*ind,tl,mid,l,min(r,mid),type)+query(2*ind+1,mid+1,tr,max(mid+1,l),r,type);
}

void calc_res(int ind, int tl, int tr, int type){
    if(tl>tr or tree[ind][type]==0){
        return;
    }
    if(tl==tr){
        res[tl]=type+'a';
    }else{
        if(lazy[ind][type]!=-1){
            push(ind,type,tl,tr);
        }
        int mid=(tl+tr)/2;
        calc_res(2*ind,tl,mid,type);
        calc_res(2*ind+1,mid+1,tr,type);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,q;
    cin>>n>>q>>s;

    build_tree(1,0,n-1);
    while(q--){
        int l,r,type;
        cin>>l>>r>>type;
        --l;
        --r;
        for(int i=0;i<26;++i){
            counter[i]=query(1,0,n-1,l,r,i);
        }
        int limit=(type==1 ? l : r);
        for(int i=0;i<26;++i){
            if(counter[i]>0){
                update_range(1,0,n-1,l,r,i,0);
                if(type==1){
                    update_range(1,0,n-1,limit,limit+counter[i]-1,i,1);
                    limit+=counter[i];
                }else{
                    update_range(1,0,n-1,limit-counter[i]+1,limit,i,1);
                    limit-=counter[i];
                }
            }
        }
    }

    for(int i=0;i<26;++i){
        calc_res(1,0,n-1,i);
    }
    cout<<res<<endl;
return 0;
}