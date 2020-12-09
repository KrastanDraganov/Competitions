#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;

vector<int> undir_graph[MAXN],rev_teleport[MAXN];
int teleport[MAXN];

int component[MAXN],visited[MAXN];
int cycle_size[MAXN],depth_cycle[MAXN];
bool in_cycle[MAXN];

void dfs_comps(int currv, int id){
    component[currv]=id;
    for(int nextv : undir_graph[currv]){
        if(component[nextv]==-1){
            dfs_comps(nextv, id);
        }
    }
}

void dfs_cycle(int currv, int n){
    int id=currv;
    int curr_comp=component[currv];
    
    while(visited[currv]==-1){
        visited[currv]=id;
        currv=teleport[currv];
    }

    while(visited[currv]==id){
        in_cycle[currv]=true;
        ++cycle_size[curr_comp];
        visited[currv]+=n;
        currv=teleport[currv];
    }
}

void dfs_depth(int currv){
    for(int nextv : rev_teleport[currv]){
        if(!in_cycle[nextv]){
            depth_cycle[nextv]=depth_cycle[currv]+1;
            dfs_depth(nextv);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        component[i]=-1;
        visited[i]=-1;
    }

    for(int from=0;from<n;++from){
        int to;
        cin>>to;
        --to;

        teleport[from]=to;
        rev_teleport[to].push_back(from);

        undir_graph[from].push_back(to);
        undir_graph[to].push_back(from);
    }

    int all_components=0;
    for(int i=0;i<n;++i){
        if(component[i]==-1){
            dfs_comps(i, all_components++);
        }
    }

    for(int i=0;i<n;++i){
        if(visited[i]==-1){
            dfs_cycle(i, n);
        }
    }

    for(int i=0;i<n;++i){
        if(in_cycle[i]){
            dfs_depth(i);
        }
    }

    for(int i=0;i<n;++i){
        int curr_comp=component[i];
        cout<<depth_cycle[i]+cycle_size[curr_comp]<<" ";
    }
    cout<<endl;
return 0;
}