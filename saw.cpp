#include<iostream>
#define endl '\n'
using namespace std;
long long dp[2][25][13];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=9;++i){
        dp[0][0][i]=1;
        dp[1][0][i]=1;
    }
    for(int i=1;i<n;++i){
        for(int i2=0;i2<=9;++i2){
            for(int i3=i2+1;i3<=9;++i3){
                dp[1][i][i3]+=dp[0][i-1][i2];
            }
            for(int i3=0;i3<i2;++i3){
                dp[0][i][i3]+=dp[1][i-1][i2];
            }
        }
    }
    long long res=0;
    for(int i=0;i<=9;++i){
        res+=dp[0][n-1][i]+dp[1][n-1][i];
    }
    cout<<res<<endl;
return 0;
}