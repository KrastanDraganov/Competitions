#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,MOD=1e9+7;
int dp[MAXN][MAXN];
vector<int> divisors[MAXN];

int sol(int ind, int num, int n){
    if(ind==n){
        return 1;
    }
    int& res=dp[ind][num];
    if(res!=-1){
        return res;
    }
    res=0;
    for(int next : divisors[num]){
        res=res+sol(ind+1,next,n);
        if(res>=MOD){
            res-=MOD;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    cin>>n>>k;
    
    for(int i=1;i<=k;++i){
        for(int i2=1;i2<=k;++i2){
            if(i%i2==0 or i2%i==0){
                divisors[i].push_back(i2);
            }
        }
    }
    
    for(int i=0;i<n;++i){
        for(int i2=0;i2<=k;++i2){
            dp[i][i2]=-1;
        }
    }
    cout<<sol(0,1,n)<<endl;
return 0;
}