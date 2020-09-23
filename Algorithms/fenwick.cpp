#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
long long tree[MAXN],nums[MAXN];

void update(int ind, long long value, int n){
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
    
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        update(i,nums[i],n);
    }
    
    for(int i=0;i<m;i++){
        string s;
        int left,right;
        cin>>s>>left>>right;
        
        if(s=="UPDATE"){
            update(left,right-nums[left],n);
            nums[left]=right;
        }else{
            cout<<sum(right)-sum(left-1)<<endl;
        }
    }
return 0;
}