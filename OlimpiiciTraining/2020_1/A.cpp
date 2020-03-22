#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
long long nums[MAXN],diffs[MAXN][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    for(int i=0;i<n;++i){
        diffs[i][0]=abs(nums[i]-nums[n-i-1]);
        diffs[i][1]=abs(nums[i]-nums[n-i-2]);
    }
    long long res=0;
    for(int removed=0;removed<n;++removed){
        int l=(removed==0 ? 1 : 0),r=(removed==n-1 ? n-2 : n-1);
        long long curr_gcd=0;
        while(l<=r){
            long long diff=abs(nums[r]-nums[l]);
            curr_gcd=__gcd(curr_gcd,diff);
            ++l;
            --r;
            if(l==removed){
                ++l;
            }else if(r==removed){
                --r;
            }
        }
        //cout<<removed<<" "<<curr_gcd<<endl;
        res=max(res,curr_gcd);
    }
    cout<<res<<endl;
return 0;
}