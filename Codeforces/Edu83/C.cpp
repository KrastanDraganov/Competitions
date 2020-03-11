#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=33;
long long nums[MAXN];

bool is_res(int n, int k){
    long long max_power=k;
    while(max_power<=(1e16)){
        max_power*=k;
    }
    while(max_power>0){
        bool check=false;
        for(int i=0;i<n;++i){
            if(nums[i]>=max_power){
                if(check){
                    return false;
                }
                nums[i]-=max_power;
                check=true;
            }
        }
        max_power/=k;
    }
    for(int i=0;i<n;++i){
        if(nums[i]>0){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;++i){
            cin>>nums[i];
        }
        cout<<(is_res(n,k) ? "YES" : "NO")<<endl;
    }
return 0;
}