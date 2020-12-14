#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[2][MAXN];
bool visited[MAXN];
int comp[MAXN];

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

    int all_components=0;
    for(int i=n-1;i>=0;--i){
        int currv=topo[i];
        if(comp[currv]==-1){
            dfs2(currv, ++all_components);
        }
    }

    cout<<all_components<<endl;
    for(int i=0;i<n;++i){
        cout<<comp[i]<<" ";
    }
    cout<<endl;
return 0;
}