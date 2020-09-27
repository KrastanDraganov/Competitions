#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3;
int points[MAXN];
long long dp[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    long long sum=0;
    for(int i=0;i<n;++i){
        cin>>points[i];
        dp[i][i]=points[i];
        sum+=points[i];
    }

    for(int l=n-2;l>=0;--l){
        for(int r=l+1;r<n;++r){
            dp[l][r]=max(points[l]-dp[l+1][r],points[r]-dp[l][r-1]);
        }
    }

    cout<<(sum+dp[0][n-1])/2<<endl;
return 0;
}