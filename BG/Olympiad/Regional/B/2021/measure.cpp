#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MOD=1e9+7;

struct NumInfo {
    int num,ind,prev_sum;

    NumInfo(int _num, int _ind, int _prev_sum){
        num=_num;
        ind=_ind;
        prev_sum=_prev_sum;
    }

    bool operator<(const NumInfo& comp) {
        return num<comp.num;
    }
};

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int mul_mod(int x, int y){
    return 1ll*x*y%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    int q;
    cin>>q;

    vector<vector<int>> queries(n);
    while(q--){
        int ind,new_value;
        cin>>ind>>new_value;
        queries[ind].push_back(new_value);
    }

    vector<NumInfo> min_nums;
    min_nums.push_back(NumInfo(0, -1, 0));

    int original_measure=0,all_measure=0;
    for(int i=0;i<n;++i){
        for(int query : queries[i]){
            int target=lower_bound(min_nums.begin(), min_nums.end(), NumInfo(query, i, 0))-min_nums.begin()-1;
            
            add_mod(all_measure, min_nums[target].prev_sum);
            add_mod(all_measure, mul_mod(query, i-min_nums[target].ind));
            add_mod(all_measure, original_measure);
        }

        while((int)min_nums.size()>1 and nums[i]<=min_nums.back().num){
            min_nums.pop_back();
        }

        int curr_sum=mul_mod(nums[i], i-min_nums.back().ind);
        add_mod(curr_sum, min_nums.back().prev_sum);
        
        add_mod(all_measure, curr_sum);
        add_mod(original_measure, curr_sum);
        
        min_nums.push_back(NumInfo(nums[i], i, curr_sum));
    }

    cout<<all_measure<<endl;
return 0;
}