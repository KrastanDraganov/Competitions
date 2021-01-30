#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

vector<vector<long long>> calc_combinations(int n){
    vector<vector<long long>> res(n+3, vector<long long>(n+3, 0));
    res[0][0]=1;

    for(int i=1;i<=n;++i){
        res[i][0]=1;
        for(int i2=1;i2<=i;++i2){
            res[i][i2]=res[i-1][i2-1]+res[i-1][i2];
        }
    }

    return res;
}

long long calc_seqs(int unique, int u, vector<int>& nums, vector<vector<long long>>& comb){
    int l=1,interval_size=0;
    long long res=1;

    for(int i=1;i<=unique+1;++i){
        if(nums[i]==-1){
            ++interval_size;
            continue;
        }

        int r=nums[i]-1;
        if(r-l+1<interval_size){
            return 0;
        }
        res*=comb[r-l+1][interval_size];

        l=nums[i]+1;
        interval_size=0;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,u;
    cin>>n>>u;

    vector<int> nums(n);
    vector<bool> used(u+1, false);
    for(int i=0;i<n;++i){
        cin>>nums[i];
        used[nums[i]]=true;
    }

    vector<int> smallest_value(u+1, -1);
    int unique=0;
    for(int i=1;i<=u;++i){
        if(used[i]){
            smallest_value[i]=++unique;
        }
    }

    vector<vector<long long>> comb=calc_combinations(u);
    long long target=(comb[u][unique]+1)/2;

    vector<int> res(unique+3, -1);
    res[unique+1]=u+1;

    for(int i=0;i<n;++i){
        nums[i]=smallest_value[nums[i]];
        
        if(res[nums[i]]!=-1){
            continue;
        }

        for(int i2=nums[i];i2<=u;++i2){
            res[nums[i]]=i2;
            
            long long curr_seqs=calc_seqs(unique, u, res, comb);
            if(curr_seqs>=target){
                break;
            }

            target-=curr_seqs;
        }
    }

    for(int i=0;i<n;++i){
        cout<<res[nums[i]]<<" ";
    }
    cout<<endl;
return 0;
}