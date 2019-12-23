#include<iostream>
#include<unordered_map>
#include<set>
#define endl '\n'
#define MAXN 150002
using namespace std;
int nums[MAXN];
set<int> row;
unordered_map<int,int> counter;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    int res=0,ind_res=0,beg=0;
    for(int i=0;i<n;++i){
        row.insert(nums[i]);
        ++counter[nums[i]];
        if(row.size()>k){
            while(counter[nums[beg]]>1){
                --counter[nums[beg++]];
            }
            counter[nums[beg]]=0;
            row.erase(nums[beg++]);
        }
        if(res<i-beg+1){
            res=i-beg+1;
            ind_res=beg;
        }
    }
    cout<<res<<" "<<ind_res+1<<endl;
return 0;
}