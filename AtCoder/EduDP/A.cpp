#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int dp[MAXN],height[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>height[i];
        dp[i]=1e9;
    }
    dp[0]=0;
    for(int i=1;i<n;++i){
        for(int i2=1;i2<3;++i2){
            if(i2<=i){
                dp[i]=min(dp[i],dp[i-i2]+abs(height[i]-height[i-i2]));
            }
        }
    }
    cout<<dp[n-1]<<endl;
return 0;
}