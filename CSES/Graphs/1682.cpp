#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[2][MAXN];
bool visited[MAXN];
int comp[MAXN],in_degree[MAXN];

void dfs1(int currv, vector<int>& topo){
    visited[currv]=true;
    for(int nextv : graph[0][currv]){
        if(!visited[nextv]){
            dfs1(nextv, topo);
        }
    }
    topo.push_back(currv);
}

void dfs2(int currv, int id){
    comp[currv]=id;
    for(int nextv : graph[1][currv]){
        if(comp[nextv]==-1){
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
        --from;
        --to;
        graph[0][from].push_back(to);
        graph[1][to].push_back(from);
    }
    
    vector<int> topo;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            dfs1(i, topo);
        }
    }

    for(int i=0;i<n;++i){
        comp[i]=-1;
    }

    vector<int> scc;
    for(int i=n-1;i>=0;--i){
        int currv=topo[i];
        if(comp[currv]==-1){
            dfs2(currv, (int)scc.size());
            scc.push_back(currv+1);
        }
    }

    for(int currv=0;currv<n;++currv){
        for(int nextv : graph[0][currv]){
            if(comp[currv]!=comp[nextv]){
                ++in_degree[comp[nextv]];
            }
        }
    }
    
    int all_components=(int)scc.size();
    if(all_components==1){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";

        int vertex1=-1,vertex2=-1;
        for(int i=0;i<all_components;++i){
            if(in_degree[i]==0 and vertex2==-1){
                vertex2=scc[i];
                continue;
            }
            vertex1=scc[i];
        }

        cout<<vertex1<<" "<<vertex2<<endl;
    }
return 0;
}