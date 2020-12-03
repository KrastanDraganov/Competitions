#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MOD=1e9+7;
const long long INF=(long long)(1e18);

struct DijkstraEntry {
    int vertex;
    long long dist;

    DijkstraEntry(int _vertex=-1, long long _dist=INF){
        vertex=_vertex;
        dist=_dist;
    }

    bool operator>(const DijkstraEntry& comp) const {
        return dist>comp.dist;
    }
};

struct Result {
    int all_routes,min_flights,max_flights;
    long long dist;

    Result(long long _dist=INF, int _all_routes=0, int _min_flights=2*MAXN, int _max_flights=0){
        dist=_dist;
        all_routes=_all_routes;
        min_flights=_min_flights;
        max_flights=_max_flights;
    }

    void print(){
        cout<<dist<<" "<<all_routes<<" "<<min_flights<<" "<<max_flights<<endl;
    }
};

vector<pair<int, int>> graph[MAXN];
Result res[MAXN];
bool visited[MAXN];

void self_min(int& x, int y){
    x=min(x, y);
}

void self_max(int& x, int y){
    x=max(x, y);
}

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

void find_shortest_paths(int n){
    priority_queue<DijkstraEntry, vector<DijkstraEntry>, greater<DijkstraEntry>> dijkstra;
    dijkstra.push(DijkstraEntry(0, 0));
    res[0]=Result(0, 1, 0, 0);

    while(!dijkstra.empty()){
        int currv=dijkstra.top().vertex;
        dijkstra.pop();

        if(visited[currv]){
            continue;
        }
        visited[currv]=true;

        for(auto [nextv, edge] : graph[currv]){
            long long new_dist=res[currv].dist+edge;
            
            if(new_dist>res[nextv].dist){
                continue;
            }

            if(new_dist==res[nextv].dist){
                add_mod(res[nextv].all_routes, res[currv].all_routes);
                self_min(res[nextv].min_flights, res[currv].min_flights+1);
                self_max(res[nextv].max_flights, res[currv].max_flights+1);
                continue;
            }

            res[nextv].dist=new_dist;
            res[nextv].all_routes=res[currv].all_routes;
            res[nextv].min_flights=res[currv].min_flights+1;
            res[nextv].max_flights=res[currv].max_flights+1;

            dijkstra.push(DijkstraEntry(nextv, new_dist));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int from,to,price;
        cin>>from>>to>>price;
        --from;
        --to;
        graph[from].push_back({to, price});
    }

    find_shortest_paths(n);
    res[n-1].print();
return 0;
}