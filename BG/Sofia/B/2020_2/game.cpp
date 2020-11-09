#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e4+3;
long long prefix[MAXN];

int best_score(int nums_l, int nums_r, long long target){
    if(target%2==1 or nums_l>nums_r){
        return 0;
    }
    target/=2;

    int l=nums_l,r=nums_r-1;
    while(l<=r){
        int mid=(l+r)/2;
        long long curr_sum=prefix[mid]-prefix[nums_l-1];

        if(curr_sum>=target){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    if(r+1==nums_r or prefix[r+1]-prefix[nums_l-1]!=target){
        return 0;
    }

    return 1+max(best_score(nums_l, r+1, target), best_score(r+2, nums_r, target));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    
    while(tests--){
        int n;
        cin>>n;
        
        for(int i=0;i<n;++i){
            long long num;
            cin>>num;
            prefix[i+1]=prefix[i]+num;
        }

        cout<<best_score(1, n, prefix[n])<<endl;
    }
return 0;
}