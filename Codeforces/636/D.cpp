#include<iostream>
#include<utility>
#include<algorithm>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int nums[MAXN],sums[2*MAXN],prefix[2*MAXN];

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

        for(int i=0;i<=2*k+3;++i){
            sums[i]=0;
            prefix[i]=0;
        }
        for(int i=0;i<n/2;++i){
            int num1=min(nums[i],nums[n-i-1]),num2=max(nums[i],nums[n-i-1]);
            ++sums[num1+num2];
            ++prefix[num1+1];
            --prefix[num2+k+1];
        }
        for(int i=1;i<=2*k;++i){
            prefix[i]+=prefix[i-1];
        }

        int res=2e9;
        for(int i=2;i<=2*k;++i){
            res=min(res,prefix[i]-sums[i]+2*((n/2)-prefix[i]));
        }
        cout<<res<<endl;
    }
return 0;
}