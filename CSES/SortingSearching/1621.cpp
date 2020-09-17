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

    int res=1;
    for(int i=1;i<n;++i){
        if(nums[i]!=nums[i-1]){
            ++res;
        }
    }
    cout<<res<<endl;
return 0;
}