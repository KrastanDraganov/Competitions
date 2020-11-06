#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1603;
vector<int> graph[2][MAXN];
int component[MAXN],in_degree[MAXN],out_degree[MAXN];
bool visited[MAXN];

void dfs(int currv, vector<int>& topo){
    visited[currv]=true;
    for(int nextv : graph[0][currv]){
        if(!visited[nextv]){
            dfs(nextv, topo);
        }
    }
    topo.push_back(currv);
}

void dfs2(int currv, int id){
    component[currv]=id;
    for(int nextv : graph[1][currv]){
        if(component[nextv]==-1){
            dfs2(nextv, id);
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
        graph[0][from].push_back(to);
        graph[1][to].push_back(from);
    }

    vector<int> topo;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            dfs(i, topo);
        }
    }

    for(int i=0;i<n;++i){
        component[i]=-1;
    }
    int all_scc=0;
    for(int i=n-1;i>=0;--i){
        if(component[topo[i]]==-1){
            dfs2(topo[i], all_scc++);
        }
    }

    for(int currv=0;currv<n;++currv){
        for(int nextv : graph[0][currv]){
            if(component[currv]!=component[nextv]){
                ++out_degree[component[currv]];
                ++in_degree[component[nextv]];
            }
        }
    }

    int min_sent=0,min_added=0;
    for(int i=0;i<all_scc;++i){
        if(in_degree[i]==0){
            ++min_sent;
        }
        if(out_degree[i]==0){
            ++min_added;
        }
    }
    
    min_added=max(min_added, min_sent);
    if(all_scc==1){
        min_added=0;
    }
    
    cout<<min_sent<<" "<<min_added<<endl;
return 0;
}