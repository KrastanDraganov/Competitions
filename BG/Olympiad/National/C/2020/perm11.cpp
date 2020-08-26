#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=103,MOD=1e9+7;
int dp[MAXN][MAXN][11];

void add(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int mul(int x, int y){
    return (long long) x*y%MOD;
}

void precalc(int n){
    vector<int> nums;
    for(int i=1;i<=n;++i){
        nums.push_back(i);
    }
    do{
        int rem=0;
        for(int curr : nums){
            rem=(10*rem+curr)%11;
        }
        ++dp[n][(n+1)/2][rem];
    }while(next_permutation(nums.begin(),nums.end()));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=1;i<=min(9,n);++i){
        precalc(i);
    }
    for(int i=10;i<=n;++i){
        int x=i/10,y=i%10;
        for(int even=0;even<=i;++even){
            for(int rem=0;rem<11;++rem){
                add(dp[i][even+1][(rem+y-x+11)%11],mul(even,dp[i-1][even][rem]));
                add(dp[i][even][(rem+x-y+11)%11],mul(i-even,dp[i-1][even][rem]));
            }
        }
    }

    int res=0;
    for(int i=0;i<=n+1;++i){
        add(res,dp[n][i][0]);
    }
    cout<<res<<endl;
return 0;
}