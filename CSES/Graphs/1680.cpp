#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];
int dp[MAXN],parent[MAXN];
bool visited[MAXN];

void dfs(int currv, vector<int>& topo){
    visited[currv]=true;
    for(int nextv : graph[currv]){
        if(!visited[nextv]){
            dfs(nextv, topo);
        }
    }
    topo.push_back(currv);
}

vector<int> find_path(int n){
    vector<int> path;
    
    int currv=n-1;
    while(currv!=-1){
        path.push_back(currv);
        currv=parent[currv];
    }

    reverse(path.begin(), path.end());
    return path;
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
    parent[0]=-1;
    for(int currv : topo){
        if(dp[currv]==0){
            continue;
        }

        for(int nextv : graph[currv]){
            if(dp[nextv]<dp[currv]+1){
                dp[nextv]=dp[currv]+1;
                parent[nextv]=currv;
            }
        }
    }

    if(dp[n-1]==0){
        cout<<"IMPOSSIBLE\n";
    }else{
        vector<int> path=find_path(n);

        cout<<(int)path.size()<<endl;
        for(int currv : path){
            cout<<currv+1<<" ";
        }
        cout<<endl;
    }
return 0;
}