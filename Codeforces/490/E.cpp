#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3;
vector<int> graph[3][MAXN],topo;
int comp[MAXN],in[MAXN];
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
    for(int nextv : graph[1][currv]){
        if(!visited[nextv]){
            dfs2(nextv,id);
        }
    }
}

void dfs3(int currv){
    visited[currv]=true;
    for(int nextv : graph[2][currv]){
        if(!visited[nextv]){
            dfs3(nextv);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s;
    cin>>n>>m>>s;
    --s;
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
        visited[currv]=false;
        for(int nextv : graph[0][currv]){
            if(comp[currv]!=comp[nextv]){
                graph[2][comp[currv]].push_back(comp[nextv]);
                ++in[comp[nextv]];
            }
        }
    }
    dfs3(comp[s]);

    int res=0;
    for(int i=0;i<counter;++i){
        if(!visited[i] and in[i]==0){
            ++res;
        }
    }
    cout<<res<<endl;
return 0;
}