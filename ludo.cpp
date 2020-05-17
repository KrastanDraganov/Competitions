#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=5e5+3;
vector<int> graph[MAXN];
bool used[MAXN],dp[MAXN],res[MAXN];

void dfs(int currv){
    used[currv]=true;
    for(int nextv : graph[currv]){
        if(!used[nextv]){
            dfs(nextv);
            dp[currv] |= !dp[nextv];
        }
    }
}

void dfs2(int currv, int parent, bool prev){
    res[currv]=!(dp[currv] | prev);
    int zeroes=0;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            zeroes+=!dp[nextv];
        }
    }
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            bool new_prev=false;
            if(!prev and zeroes-!dp[nextv]==0){
                new_prev=true;
            }
            dfs2(nextv,currv,new_prev);
        }
    }
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
        graph[to].push_back(from);
    }

    for(int i=0;i<n;++i){
        if(!used[i]){
            dfs(i);
            dfs2(i,-1,false);
        }
    }

    for(int i=0;i<n;++i){
        cout<<res[i];
    }
    cout<<endl;
return 0;
}