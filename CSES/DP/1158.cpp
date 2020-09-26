#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,MAXP=1e5+3;
int prices[MAXN],pages[MAXN],dp[MAXN][MAXP];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;

    for(int i=0;i<n;++i){
        cin>>prices[i];
    }
    for(int i=0;i<n;++i){
        cin>>pages[i];
    }

    for(int book=1;book<=n;++book){
        for(int sum=0;sum<=x;++sum){
            dp[book][sum]=dp[book-1][sum];
            if(prices[book-1]<=sum){
                dp[book][sum]=max(dp[book][sum],dp[book-1][sum-prices[book-1]]+pages[book-1]);
            }
        }
    }

    cout<<dp[n][x]<<endl;
return 0;
}