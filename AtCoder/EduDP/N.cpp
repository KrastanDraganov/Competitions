#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=403;
long long dp[MAXN][MAXN],prefix[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            dp[i][i2]=1e17;
        }
    }
    for(int i=0;i<n;++i){
        long long slime;
        cin>>slime;
        dp[i][i]=0;
        prefix[i+1]=prefix[i]+slime;
    }
    for(int range=1;range<n;++range){
        for(int l=0;l+range<n;++l){
            int r=l+range;
            for(int mid=l;mid<r;++mid){
                dp[l][r]=min(dp[l][r],dp[l][mid]+dp[mid+1][r]+prefix[r+1]-prefix[l]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
return 0;
}