#include<iostream>
#include<unordered_map>
#include<vector>

#define endl '\n'

using namespace std;

const int BASE=97;

vector<uint64_t> find_hashes(vector<int>& nums, int w, int k){
    int n=(int)nums.size();

    uint64_t pow_limit=1;
    for(int i=1;i<=k;++i){
        pow_limit*=BASE;
    }

    uint64_t curr_hash=nums[0];
    int len=1;

    vector<uint64_t> res;
    for(int i=1;i<n;++i){
        if((w==1 and nums[i]<=nums[i-1]) or (w==2 and nums[i]!=nums[i-1])){
            curr_hash=0;
            len=0;
        }

        curr_hash=curr_hash*BASE+nums[i];
        ++len;

        if(len>k){
            curr_hash-=pow_limit*nums[i-k];
        }

        if(len>=k){
            res.push_back(curr_hash);
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w,k,n;
    cin>>w>>k>>n;

    vector<int> nums_a(n);
    for(int i=0;i<n;++i){
        cin>>nums_a[i];
    }

    int m;
    cin>>m;

    vector<int> nums_b(m);
    for(int i=0;i<m;++i){
        cin>>nums_b[i];
    }

    vector<uint64_t> hash_a=find_hashes(nums_a, w, k);
    vector<uint64_t> hash_b=find_hashes(nums_b, w, k);

    unordered_map<uint64_t, int> counter;
    for(uint64_t curr : hash_a){
        ++counter[curr];
    }

    int res=0;
    for(uint64_t curr : hash_b){
        res+=counter[curr];
    }

    cout<<res<<endl;
return 0;
}