#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3,MAXL=21;
int fenwick[MAXN];

void tree_add(int ind, int type){
    while(ind<MAXN){
        fenwick[ind]+=type;
        ind+=(ind & (-ind));
    }
}

int sum(int ind){
    int res=0;
    while(ind>0){
        res+=fenwick[ind];
        ind-=(ind & (-ind));
    }
}

int search_pos(int counter, int n){
    int pos=0;
    for(int i=MAXL;i>=0;--i){
        int new_pos=(pos | (1<<i));
        if(new_pos<=n and counter-fenwick[new_pos]>0){
            pos=new_pos;
            counter-=fenwick[pos];
        }
    }
    return (pos==n ? 0 : pos+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        tree_add(curr,1);
    }
    
    while(q--){
        int curr;
        cin>>curr;
        if(curr>0){
            tree_add(curr,1);
        }else{
            curr=-curr;
            int ind=search_pos(curr,n);
            tree_add(ind,-1);
        }
    }

    cout<<search_pos(1,n)<<endl;
return 0;
}