#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3,MAXL=20;

vector<int> undir_graph[MAXN],rev_teleport[MAXN];
int teleport[MAXN][MAXL];

int component[MAXN],visited[MAXN];
int cycle_pos[MAXN],cycle_size[MAXN],depth_cycle[MAXN];
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
        currv=teleport[currv][0];
    }

    while(visited[currv]==id){
        in_cycle[currv]=true;
        cycle_pos[currv]=cycle_size[curr_comp]++;
        visited[currv]+=n;
        currv=teleport[currv][0];
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

int teleport_planet(int currv, int dist){
    if(dist<0){
        return -1;
    }

    int res=currv;
    for(int i=MAXL-1;i>=0;--i){
        if((1<<i) & dist){
            res=teleport[res][i];
        }
    }
    
    return res;
}

int calc_dist(int from, int to){
    if(component[from]!=component[to]){
        return -1;
    }
    int curr_comp=component[from];

    if(!in_cycle[to]){
        int target=teleport_planet(from, depth_cycle[from]-depth_cycle[to]);
        if(target!=to){
            return -1;
        }
        return depth_cycle[from]-depth_cycle[to];
    }

    int res=0;
    if(!in_cycle[from]){
        res+=depth_cycle[from];
        from=teleport_planet(from, depth_cycle[from]);
    }
    res+=(cycle_pos[to]-cycle_pos[from]+cycle_size[curr_comp])%cycle_size[curr_comp];

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;++i){
        component[i]=-1;
        visited[i]=-1;
    }

    for(int from=0;from<n;++from){
        int to;
        cin>>to;
        --to;

        teleport[from][0]=to;
        rev_teleport[to].push_back(from);

        undir_graph[from].push_back(to);
        undir_graph[to].push_back(from);
    }

    for(int i=1;i<MAXL;++i){
        for(int currv=0;currv<n;++currv){
            teleport[currv][i]=teleport[teleport[currv][i-1]][i-1];
        }
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

    while(q--){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        cout<<calc_dist(from, to)<<endl;
    }
return 0;
}