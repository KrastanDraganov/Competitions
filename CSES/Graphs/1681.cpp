#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MOD=1e9+7;
vector<int> graph[MAXN];
int dp[MAXN];
bool visited[MAXN];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

void dfs(int currv, vector<int>& topo){
    visited[currv]=true;
    for(int nextv : graph[currv]){
        if(!visited[nextv]){
            dfs(nextv, topo);
        }
    }
    topo.push_back(currv);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
    }

    vector<int> topo;
    dfs(0, topo);
    reverse(topo.begin(), topo.end());

    dp[0]=1;
    for(int currv : topo){
        for(int nextv : graph[currv]){
            add_mod(dp[nextv], dp[currv]);
        }
    }

    cout<<dp[n-1]<<endl;
return 0;
}