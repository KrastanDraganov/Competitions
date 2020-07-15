#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=20;
long long dp[MAXN][9*MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=9;++i){
        dp[1][i]=1;
    }
    for(int curr=2;curr<=n;++curr){
        for(int sum=1;sum<=9*curr;++sum){
            for(int i=0;i<=9 and i<=sum;++i){
                dp[curr][sum]+=dp[curr-1][sum-i];
            }
        }
    }

    while(q--){
        long long curr;
        cin>>curr;

        int digits=0,sum=0;
        while(curr>0){
            sum+=(curr%10);
            curr/=10;
            ++digits;
        }

        long long res=(sum>1);
        for(int i=digits+1;i<=n;++i){
            for(int i2=1;i2<sum;++i2){
                res+=dp[i][i2];
            }
        }
        cout<<res<<" ";
    }
    cout<<endl;
return 0;
}