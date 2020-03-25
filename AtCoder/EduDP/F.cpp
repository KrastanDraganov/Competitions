#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=3e3+3;
int dp[MAXN][MAXN];
char res[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=m;++i2){
            if(a[i-1]==b[i2-1]){
                dp[i][i2]=dp[i-1][i2-1]+1;
            }else{
                dp[i][i2]=max(dp[i-1][i2],dp[i][i2-1]);
            }
        }
    }
    int ind=dp[n][m]-1,i=n,i2=m;
    while(i>0 and i2>0){
        if(a[i-1]==b[i2-1]){
            res[ind--]=a[i-1];
            --i;
            --i2;
        }else if(dp[i-1][i2]>dp[i][i2-1]){
            --i;
        }else{
            --i2;
        }
    }
    for(int i=0;i<dp[n][m];++i){
        cout<<res[i];
    }
    cout<<endl;
return 0;
}