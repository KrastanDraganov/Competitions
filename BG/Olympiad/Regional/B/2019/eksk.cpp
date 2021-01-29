#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
vector<int> graph[MAXN];
int max_dist[MAXN],parent[MAXN];
bool on_main_path[MAXN];

void dfs_path(int currv){
    for(int nextv : graph[currv]){
        if(nextv==parent[currv]){
            continue;
        }
        parent[nextv]=currv;
        dfs_path(nextv);
    }
}

void dfs_dist(int currv){
    max_dist[currv]=0;
    for(int nextv : graph[currv]){
        if(nextv==parent[currv]){
            continue;
        }

        dfs_dist(nextv);
        if(on_main_path[nextv]){
            continue;
        }

        max_dist[currv]=max(max_dist[currv], max_dist[nextv]+1);
    }
}

int find_max_route(int startv, int endv, vector<int>& main_path){
    int path_size=(int)main_path.size();

    int max_cities=0,res=0;
    for(int i=0;i<path_size-1;++i){
        int currv=main_path[i];
        int nextv=main_path[i+1];

        max_cities=max(max_cities, max_dist[currv]+i+1);
        res=max(res, min(max_cities, max_dist[nextv]+path_size-i-1));
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

    parent[startv]=-1;
    dfs_path(startv);

    vector<int> main_path;
    for(int currv=endv;currv!=startv;currv=parent[currv]){
        main_path.push_back(currv);
        on_main_path[currv]=true;
    }
    
    main_path.push_back(startv);
    on_main_path[startv]=true;
    reverse(main_path.begin(), main_path.end());

    dfs_dist(startv);

    cout<<find_max_route(startv, endv, main_path)<<endl;
return 0;
}