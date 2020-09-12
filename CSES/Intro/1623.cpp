#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> nums(n);
    long long sum=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        sum+=nums[i];
    }

    long long res=sum;
    for(int mask=1;mask<(1<<n)-1;++mask){
        long long curr=0;
        for(int i=0;i<n;++i){
            if(mask & (1<<i)){
                curr+=nums[i];
            }
        }
        res=min(res,abs(sum-2*curr));
    }
    cout<<res<<endl;
return 0;
}