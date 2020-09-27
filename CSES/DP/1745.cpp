#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=103,MAXS=1e5+3;
int coins[MAXN];
bool dp[MAXN][MAXS];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>coins[i];
    }

    dp[0][0]=true;
    for(int i=1;i<=n;++i){
        for(int sum=0;sum<MAXS;++sum){
            dp[i][sum]=dp[i-1][sum];
            if(coins[i-1]<=sum){
                dp[i][sum] |= dp[i-1][sum-coins[i-1]];
            }
        }
    }

    vector<int> res;
    for(int sum=1;sum<MAXS;++sum){
        if(dp[n][sum]){
            res.push_back(sum);
        }
    }

    cout<<(int)res.size()<<endl;
    for(int sum : res){
        cout<<sum<<" ";
    }
    cout<<endl;
return 0;
}