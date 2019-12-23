#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define endl '\n'
#define MAXN 10005
using namespace std;
pair<int,int> nums[10005];
vector<pair<int,int>> res;
int main(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        nums[i]=make_pair(a,b);
    }
    sort(nums,nums+n);
    int startp=nums[0].first,endp=nums[0].second;
    for(int i=1;i<n;i++){
        if(i>0 and nums[i].first>endp+1){
            res.push_back(make_pair(startp,endp));
            startp=nums[i].first;
            endp=nums[i].second;
        }else if(nums[i].second>endp){
            endp=nums[i].second;
        }
    }
    cout<<res.size()+1<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    cout<<startp<<" "<<endp<<endl;
return 0;
}
