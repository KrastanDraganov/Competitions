#include<iostream>
#include<vector>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=3e3+3;
vector<int> graph[MAXN];
int parent[MAXN][MAXN],counter[MAXN][MAXN];
long long dp[MAXN][MAXN];
void dfs(int curr, int root){
    counter[root][curr]=1;
    for(int nextv : graph[curr]){
        if(nextv!=parent[root][curr]){
            parent[root][nextv]=curr;
            dfs(nextv,root);
            counter[root][curr]+=counter[root][nextv];
        }
    }
}
long long calc_dp(int from, int to){
    if(from==to){
        return 0;
    }
    if(dp[from][to]!=-1){
        return dp[from][to];
    }
    return dp[from][to]=counter[from][to]*counter[to][from]+max(calc_dp(from,parent[from][to]),calc_dp(parent[to][from],to));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i=0;i<n;++i){
        parent[i][i]=-1;
        dfs(i,i);
    }
    long long ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            ans=max(ans,calc_dp(i,i2));
        }
    }
    cout<<ans<<endl;
return 0;
}