#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=3e5+3;
int defeated[MAXN],tree[4*MAXN];

void update(int ind, int tl, int tr, int l, int r, int winner){
    if(l>tr or r<tl){
        return;
    }
    if(l==tl and r==tr){
        if(tree[ind]==(tr-tl+1)){
            return;
        }
        if(tr==tl){
            defeated[tl]=winner;
            tree[ind]=1;
            return;
        }
    }
    int mid=(tl+tr)/2;
    update(2*ind,tl,mid,l,min(mid,r),winner);
    update(2*ind+1,mid+1,tr,max(l,mid+1),r,winner);
    tree[ind]=tree[2*ind]+tree[2*ind+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int l,r,winner;
        cin>>l>>r>>winner;
        int firstl=l-1,firstr=winner-2,secondl=winner,secondr=r-1;
        if(firstl<=firstr){
            update(1,0,n-1,firstl,firstr,winner);
        }
        if(secondl<=secondr){
            update(1,0,n-1,secondl,secondr,winner);
        }
    }

    for(int i=0;i<n;++i){
        cout<<defeated[i]<<" ";
    }
    cout<<endl;
return 0;
}