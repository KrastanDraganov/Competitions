#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3;
pair<int,int> nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;

    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        nums[i]={curr,i+1};
    }
    sort(nums,nums+n);

    for(int i=0;i<n;++i){
        int l=i+1;
        int r=n-1;
        int target=x-nums[i].first;

        while(l<r){
            int sum=nums[l].first+nums[r].first;
            if(sum==target){
                cout<<nums[i].second<<" "<<nums[l].second<<" "<<nums[r].second<<endl;
                return 0;
            }else if(sum>target){
                --r;
            }else{
                ++l;
            }
        }
    }

    cout<<"IMPOSSIBLE\n";
return 0;
}