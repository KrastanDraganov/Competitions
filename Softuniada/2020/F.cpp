#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k,n;
    cin>>k>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    
    int diff=1e9;
    for(int i=0;i<n-k+1;++i){
        diff=min(diff,nums[i+k-1]-nums[i]);
    }
    cout<<diff<<endl;
return 0;
}