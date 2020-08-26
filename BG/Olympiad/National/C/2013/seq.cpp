#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
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
    
    int last_num=-1,last_diff=0,counter=1;
    long long ans=0;
    for(int i=1;i<n;++i){
        if(nums[i]==nums[i-1]){
            ++counter;
        }else{
            if(last_num!=-1){
                ans+=(long long)counter*(nums[i-1]-nums[last_num]+last_diff);
                last_diff+=(nums[i-1]-nums[last_num]);
            }
            last_num=i-1;
            counter=1;
        }
    }

    ans+=counter*(nums[n-1]+last_diff-nums[last_num]);
    cout<<ans<<endl;
return 0;
}