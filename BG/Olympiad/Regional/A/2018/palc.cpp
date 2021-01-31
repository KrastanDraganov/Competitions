#include<iostream>
#include<vector>
#include<string>

#define endl '\n'

using namespace std;

const int MOD=1e9+7;

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin>>s;

    int n=(int)s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int len=1;len<=n;++len){
        for(int l=0;l+len-1<n;++l){
            int r=l+len-1;
            
            if(len==1){
                dp[l][r]=1;
                continue;
            }
            if(len==2){
                dp[l][r]=(s[l]==s[r] ? 3 : 2);
                continue;
            }

            if(s[l]==s[r]){
                add_mod(dp[l][r], 1);
                add_mod(dp[l][r], dp[l+1][r-1]);
            }

            add_mod(dp[l][r], dp[l+1][r]);
            add_mod(dp[l][r], dp[l][r-1]);
            add_mod(dp[l][r], -dp[l+1][r-1]+MOD);
        }
    }

    cout<<dp[0][n-1]<<endl;
return 0;
}