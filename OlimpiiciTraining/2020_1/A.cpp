#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<long long> nums;

long long calc_res(int n){
    stack<long long> diffs;
    diffs.push(0);
    for(int i=(n/2);i>=1;--i){
        diffs.push(__gcd(abs(nums[i]-nums[n-i]),diffs.top()));
    }
    long long outside=0,res=0;
    for(int i=0;i<n/2+1;++i){
        long long curr=__gcd(outside,diffs.top());
        diffs.pop();
        res=max(res,curr);
        outside=__gcd(outside,abs(nums[i]-nums[n-i-1]));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        long long curr;
        cin>>curr;
        nums.push_back(curr);
    }
    long long ans=calc_res(n);
    reverse(nums.begin(),nums.end());
    ans=max(ans,calc_res(n));
    cout<<ans<<endl;
return 0;
}