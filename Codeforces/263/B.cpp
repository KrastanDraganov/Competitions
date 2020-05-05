#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MOD=1e9+7;
vector<int> graph[MAXN];
bool is_black[MAXN];
int dp[MAXN][2];

int mul(int num1, int num2){
    return (long long) num1*num2%MOD;
}

void dfs(int currv, int parent){
    if(is_black[currv]){
        dp[currv][1]=1;
    }else{
        dp[currv][0]=1;
    }
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv);
            int prev_white=dp[currv][0],prev_black=dp[currv][1];
            dp[currv][0]=(mul(prev_white,dp[nextv][0])+mul(prev_white,dp[nextv][1]))%MOD;
            dp[currv][1]=(mul(prev_black,dp[nextv][1])+mul(prev_black,dp[nextv][0]))%MOD;
            dp[currv][1]=(dp[currv][1]+mul(prev_white,dp[nextv][1]))%MOD;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int from=1;from<n;++from){
        int to;
        cin>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i=0;i<n;++i){
        cin>>is_black[i];
    }

    dfs(0,-1);
    cout<<dp[0][1]<<endl;
return 0;
}