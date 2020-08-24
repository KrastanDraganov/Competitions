#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=50;
long long dp[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int p,n,s;
    cin>>p>>n>>s;
    
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=0;i<s and i<p;i++){
        dp[1][i]=1;
    }
    
    for(int i=2;i<=n;i++){
        for(int i2=1;i2<s;i2++){
            long long counter=0;
            for(int i3=0;i3<p;i3++){
                if(i2-i3>=0){
                    counter+=dp[i-1][i2-i3];
                }
            }
            dp[i][i2]=counter;
        }
    }

    long long result=0;
    for(int i=0;i<s;i++){
        result+=dp[n][i];  
    }
    cout<<result<<endl;
return 0;
}