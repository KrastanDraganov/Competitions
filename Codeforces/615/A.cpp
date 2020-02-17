#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests,nums[3];
    cin>>tests;
    while(tests--){
        int n;
        cin>>nums[0]>>nums[1]>>nums[2]>>n;
        sort(nums,nums+3);
        n-=(2*nums[2]-nums[0]-nums[1]);
        if(n<0 or n%3){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
return 0;
}