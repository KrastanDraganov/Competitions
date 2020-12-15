#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[3][MAXN];
bool visited[MAXN];
int coins[MAXN],comp[MAXN],in_degree[MAXN];
long long dp[MAXN];

void dfs_topo(int currv, vector<int>& topo){
    visited[currv]=true;
    for(int nextv : graph[0][currv]){
        if(!visited[nextv]){
            dfs_topo(nextv, topo);
        }
    }
    topo.push_back(currv);
}

void dfs_comp(int currv, int id){
    comp[currv]=id;
    dp[id]+=coins[currv];
    for(int nextv : graph[1][currv]){
        if(comp[nextv]==-1){
            dfs_comp(nextv, id);
        }
    }
}

void dfs_dp(int currv){
    visited[currv]=true;

    long long max_coins=0;
    for(int nextv : graph[2][currv]){
        if(!visited[nextv]){
            dfs_dp(nextv);
        }
        max_coins=max(max_coins, dp[nextv]);
    }
    
    dp[currv]+=max_coins;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        cin>>coins[i];
    }

    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[0][from].push_back(to);
        graph[1][to].push_back(from);
    }
    
    vector<int> topo;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            dfs_topo(i, topo);
        }
    }

    for(int i=0;i<n;++i){
        comp[i]=-1;
    }

    int all_components=0;
    for(int i=n-1;i>=0;--i){
        int currv=topo[i];
        if(comp[currv]==-1){
            dfs_comp(currv, ++all_components);
        }
    }

    for(int currv=0;currv<n;++currv){
        for(int nextv : graph[0][currv]){
            if(comp[currv]!=comp[nextv]){
                ++in_degree[comp[nextv]];
                graph[2][comp[currv]].push_back(comp[nextv]);
            }
        }
    }
    
    for(int i=0;i<all_components;++i){
        visited[i]=false;
    }

    long long res=0;
    for(int i=0;i<all_components;++i){
        if(in_degree[i]==0){
            dfs_dp(i);
            res=max(res, dp[i]);
        }
    }

    cout<<res<<endl;
return 0;
}