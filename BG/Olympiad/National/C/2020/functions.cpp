#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3,MAXK=13,INF=1e9;
int nums[MAXK],dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin>>k;
    for(int i=0;i<k;++i){
        cin>>nums[i];
    }

    sort(nums,nums+k);
    dp[0]=0;
    for(int curr=1;curr<MAXN;++curr){
        dp[curr]=INF;
        for(int i=0;i<k and nums[i]<=curr;++i){
            dp[curr]=min(dp[curr],dp[curr-nums[i]]+1);
        }
    }

    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<(dp[x]==INF ? 0 : dp[x])<<endl;
    }
return 0;
}