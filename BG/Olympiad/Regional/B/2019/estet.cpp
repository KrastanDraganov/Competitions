#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

vector<int> find_lis(vector<int>& nums){
    int n=(int)nums.size();
    if(n==0){
        return {};
    }

    vector<int> sequences;
    sequences.push_back(nums[0]);
    int max_len=1;

    vector<int> lis(n, 1);
    for(int i=1;i<n;++i){
        if(nums[i]<sequences[0]){
            sequences[0]=nums[i];
            lis[i]=1;
            continue;
        }

        if(nums[i]>sequences[max_len-1]){
            sequences.push_back(nums[i]);
            lis[i]=++max_len;
            continue;
        }

        int target=lower_bound(sequences.begin(), sequences.end(), nums[i])-sequences.begin();
        sequences[target]=nums[i];
        lis[i]=target+1;
    }

    return lis;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> trees(n);
    for(int i=0;i<n;++i){
        cin>>trees[i];
    }

    vector<int> dp_left=find_lis(trees);

    reverse(trees.begin(), trees.end());
    vector<int> dp_right=find_lis(trees);
    reverse(dp_right.begin(), dp_right.end());

    int res=0;
    for(int i=0;i<n;++i){
        res=max(res, dp_left[i]+dp_right[i]-1);
    }

    cout<<res<<endl;
return 0;
}