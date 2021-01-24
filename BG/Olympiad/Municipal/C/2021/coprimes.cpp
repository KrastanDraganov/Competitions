#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
vector<int> divs[MAXN];

void calc_eratosthen_sieve(int n){
    vector<bool> not_prime(n+1, false);
    for(int i=2;i<=n;i+=2){
        divs[i].push_back(2);
        not_prime[i]=true;
    }
    not_prime[2]=false;

    for(int div=3;div<=n;div+=2){
        if(not_prime[div]){
            continue;
        }
        divs[div].push_back(div);

        for(int i=2*div;i<=n;i+=div){
            divs[i].push_back(div);
            not_prime[i]=true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    calc_eratosthen_sieve(MAXN);

    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    vector<int> last_used(MAXN, -1);
    int res=0,interval_start=0;
    for(int i=0;i<n;++i){
        int max_ind=-1;
        for(int div : divs[nums[i]]){
            max_ind=max(max_ind, last_used[div]);
        }

        while(interval_start<=max_ind){
            for(int div : divs[nums[interval_start]]){
                if(last_used[div]==interval_start){
                    last_used[div]=-1;
                }
            }
            ++interval_start;
        }

        for(int div : divs[nums[i]]){
            last_used[div]=i;
        }

        res=max(res, i-interval_start+1);
    }

    cout<<res<<endl;
return 0;
}