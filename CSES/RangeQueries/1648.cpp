#include<iostream>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=2e5+3;
int nums[MAXN];
long long fenwick[MAXN];
 
void add_val(int ind, int val){
    while(ind<MAXN){
        fenwick[ind]+=val;
        ind += (ind & (-ind));
    }
}
 
long long sum(int ind){
    long long res=0;
 
    while(ind>0){
        res+=fenwick[ind];
        ind -= (ind & (-ind));
    }
 
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,q;
    cin>>n>>q;
 
    for(int i=0;i<n;++i){
        cin>>nums[i];
        add_val(i+1,nums[i]);
    }
 
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
 
        if(type==2){
            cout<<sum(r)-sum(l-1)<<endl;
        }else{
            add_val(l,r-nums[l-1]);
            nums[l-1]=r;
        }
    }
return 0;
}