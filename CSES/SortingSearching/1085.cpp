#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
long long nums[MAXN];

bool check(long long target, int n, int k){
    int counter=1;
    long long sum=0;

    for(int i=0;i<n;++i){
        if(sum+nums[i]>target){
            ++counter;
            sum=0;
        }
        sum+=nums[i];
    }

    return counter>k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    long long l=0,r=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        l=max(l,nums[i]);
        r+=nums[i];
    }

    while(l<=r){
        long long mid=(l+r)/2;

        if(check(mid,n,k)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

    cout<<l<<endl;
return 0;
}