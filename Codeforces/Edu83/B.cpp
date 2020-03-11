#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN=103;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>nums[i];
        }
        sort(nums,nums+n);
        for(int i=n-1;i>=0;--i){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
return 0;
}