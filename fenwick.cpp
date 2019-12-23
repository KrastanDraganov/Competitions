#include<bits/stdc++.h>
#define endl '\n'
#define MAXN 220005
using namespace std;
long long tree[MAXN],nums[MAXN];
int n;
void update(int ind, long long value){
    while(ind<=n){
        tree[ind]+=value;
        ind+=(ind & (-ind));
    }
}
long long sum(int ind){
    long long result=0;
    while(ind>0){
        result+=tree[ind];
        ind-=(ind & (-ind));
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        update(i,nums[i]);
    }
    for(int i=0;i<m;i++){
        string s;
        int left,right;
        cin>>s>>left>>right;
        if(s=="UPDATE"){
            update(left,right-nums[left]);
            nums[left]=right;
        }else{
            cout<<sum(right)-sum(left-1)<<endl;
        }
    }
return 0;
}