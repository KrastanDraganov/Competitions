#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
vector<int> graph[3][MAXN],topo;
int fun[MAXN],comp[MAXN];
long long all_fun[MAXN],res[MAXN];
bool visited[MAXN];

void dfs(int currv){
    visited[currv]=true;
    for(int nextv : graph[0][currv]){
        if(!visited[nextv]){
            dfs(nextv);
        }
    }
    topo.push_back(currv);
}

void dfs2(int currv, int id){
    visited[currv]=true;
    comp[currv]=id;
    all_fun[id]+=(long long)fun[currv];
    for(int nextv : graph[1][currv]){
        if(!visited[nextv]){
            dfs2(nextv,id);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s,e;
    cin>>n>>m>>s>>e;
    --s;
    --e;
    for(int i=0;i<n;++i){
        cin>>fun[i];
    }
    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[0][from].push_back(to);
        graph[1][to].push_back(from);
    }

    for(int i=0;i<n;++i){
        if(!visited[i]){
            dfs(i);
        }
    }
    for(int i=0;i<n;++i){
        visited[i]=false;
    }
    int counter=0;
    for(int i=n-1;i>=0;--i){
        if(!visited[topo[i]]){
            dfs2(topo[i],counter++);
        }
    }

    for(int currv=0;currv<n;++currv){
        for(int nextv : graph[0][currv]){
            if(comp[currv]!=comp[nextv]){
                graph[2][comp[currv]].push_back(comp[nextv]);
            }
        }
    }
    for(int i=0;i<n;++i){
        visited[i]=false;
    }
    queue<int> bfs;
    bfs.push(comp[s]);
    res[comp[s]]=all_fun[comp[s]];
    while(!bfs.empty()){
        int currv=bfs.front();
        bfs.pop();
        visited[currv]=true;
        for(int nextv : graph[2][currv]){
            long long new_res=res[currv]+all_fun[nextv];
            if(!visited[nextv] and res[nextv]<new_res){
                res[nextv]=new_res;
                bfs.push(nextv);
            }
        }
    }
    cout<<res[comp[e]]<<endl;
return 0;
}