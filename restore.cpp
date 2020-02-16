#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
int tree[MAXN];
void update(int pos, int val, int n){
    while(pos<=n){
        tree[pos]+=val;
        pos+=(pos & (-pos));
    }
}
int query(int pos){
    int res=0;
    while(pos>0){
        res+=tree[pos];
        pos-=(pos & (-pos));
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        update(i,1,n);
    }
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        int l=1,r=n,diff=n-i-curr;
        while(l<=r){
            int mid=(l+r)/2;
            if(query(mid)>=diff){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(i>0){
            cout<<" ";
        }
        cout<<r+1;
        update(r+1,-1,n);
    }
    cout<<endl;
return 0;
}