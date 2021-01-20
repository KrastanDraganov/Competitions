#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,r;
    cin>>n>>r;

    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    int pivot=0;
    long long res=0;
    
    for(int i=0;i<n and pivot<n;++i){
        while(pivot<n and nums[pivot]-nums[i]<=r){
            ++pivot;
        }
        res+=(n-pivot);
    }

    cout<<res<<endl;
return 0;
}