#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    
    int ptr=0,ans=0;
    for(int i=2;i<n;++i){
        if(nums[ptr]+nums[ptr+1]<=nums[i]){
            ans=max(ans,i-ptr);
            while(ptr<i-1 and nums[ptr]+nums[ptr+1]<=nums[i]){
                ++ptr;
            }
        }
    }
    
    ans=max(ptr,n-ptr);
    cout<<(ans<3 ? 1 : ans)<<endl;
return 0;
}