#include<iostream>
#include<vector>
#include<cstring>
#define endl '\n'
#define MAXN 103
using namespace std;
int iliyan[MAXN],pesho[MAXN],ans=-1,dp[MAXN][MAXN*MAXN];
vector<bool> nz;
bool sol(int ind, int sum1, int sum2, vector<bool> role, int n){
    if(ans>=0){
        return true;
    }
    if(ind==n){
        if(sum1==sum2){
            ans=sum1;
            for(int i=0;i<n;++i){
                nz.push_back(role[i]);
            }
            return true;
        }
        return false;
    }
    if(dp[ind][sum1]!=-1){
        return (bool)dp[ind][sum1];
    }
    role.push_back(0);
    bool res=sol(ind+1,sum1+iliyan[ind],sum2,role,n);
    role.pop_back();
    role.push_back(1);
    res=max(res,sol(ind+1,sum1,sum2+pesho[ind],role,n));
    dp[ind][sum1]=res;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>iliyan[i]>>pesho[i];
    }
    memset(dp,-1,sizeof(dp));
    if(!sol(0,0,0,nz,n)){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
        for(int i=0;i<n;++i){
            cout<<(nz[i] ? 2 : 1);
            if(i<n-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
return 0;
}