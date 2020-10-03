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
    }
 
    while(q--){
        int type;
        cin>>type;
 
        if(type==1){
            int l,r,bonus;
            cin>>l>>r>>bonus;

            add_val(l, bonus);
            add_val(r+1, -bonus);
        }else{
            int ind;
            cin>>ind;

            cout<<nums[ind-1]+sum(ind)<<endl;
        }
    }
return 0;
}