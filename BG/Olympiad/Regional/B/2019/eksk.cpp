#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
vector<int> graph[MAXN];
int path_dist[MAXN],max_dist[MAXN];

void dfs_path(int currv, int parent, int endv){
    if(currv==endv){
        path_dist[currv]=1;
        return;
    }

    path_dist[currv]=-MAXN;
    for(int nextv : graph[currv]){
        if(nextv==parent){
            continue;
        }

        dfs_path(nextv, currv, endv);
        path_dist[currv]=max(path_dist[currv], path_dist[nextv]+1);
    }
}

void dfs_dist(int currv, int parent, int endv){
    max_dist[currv]=0;
    for(int nextv : graph[currv]){
        if(nextv==parent){
            continue;
        }

        dfs_dist(nextv, currv, endv);
        if(path_dist[nextv]>0){
            continue;
        }

        max_dist[currv]=max(max_dist[currv], max_dist[nextv]+1);
    }
}

int find_max_route(int startv, int endv){
    int currv=startv,parent=-1;
    int visited=1;
    int max_cities=0;

    int res=0;
    while(currv!=endv){
        int next_in_path=-1;
        for(int nextv : graph[currv]){
            if(path_dist[nextv]>0 and parent!=nextv){
                next_in_path=nextv;
                break;
            }
        }

        max_cities=max(max_cities, max_dist[currv]+visited);
        res=max(res, min(max_cities, path_dist[next_in_path]+max_dist[next_in_path]));

        ++visited;
        parent=currv;
        currv=next_in_path;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        
        --from;
        --to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int startv,endv;
    cin>>startv>>endv;
    --startv;
    --endv;

    dfs_path(startv, -1, endv);
    dfs_dist(startv, -1, endv);

    cout<<find_max_route(startv, endv)<<endl;
return 0;
}