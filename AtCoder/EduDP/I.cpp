#include<iostream>
#include<iomanip>

#define endl '\n'

using namespace std;

const int MAXN=3e3+3;
double dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=0;i<n;++i){
        double coin;
        cin>>coin;
        for(int i2=i+1;i2>=0;--i2){
            dp[i2]=(i2==0 ? 0 : dp[i2-1])*coin+dp[i2]*(1-coin);
        }
    }
    double res=0;
    for(int i=n/2+1;i<=n;++i){
        res+=dp[i];
    }
    cout<<fixed<<setprecision(10)<<res<<endl;
return 0;
}