#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
long long nums[MAXN],prefix[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    
    sort(nums,nums+n);
    for(int i=0;i<n;++i){
        prefix[i+1]=prefix[i]+nums[i];
    }

    int ind1=0;
    long long ans=1e18;
    while(ind1<n){
        int ind2=ind1+1;
        while(nums[ind2]==nums[ind1]){
            ++ind2;
        }
        long long counter=ind2-ind1;
        long long steps_left=(long long)ind1*(nums[ind1]-1)-prefix[ind1];
        long long steps_right=prefix[n]-prefix[ind2]-(long long)(n-ind2)*(nums[ind1]+1);
        if(counter>=k){
            ans=0;
            break;
        }
        if(ind2>=k){
            ans=min(ans,steps_left+k-counter);
        }
        if(n-ind1>=k){
            ans=min(ans,steps_right+k-counter);
        }
        ans=min(ans,steps_left+steps_right+k-counter);
        //cout<<ind1<<" "<<nums[ind1]<<" "<<counter<<" "<<steps_left<<" "<<steps_right<<endl;
        ind1=ind2;
    }
    cout<<max(ans,0ll)<<endl;
return 0;
}