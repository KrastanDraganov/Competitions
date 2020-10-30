#include<iostream>
#include<queue>
#include<vector>
#include<functional>

#define endl '\n'

using namespace std;

struct Edge {
    int to,len;
    bool is_dirty;

    Edge(int _to=-1, int _len=0, bool _is_dirty=false){
        to=_to;
        len=_len;
        is_dirty=_is_dirty;
    }
};

const int MAXN=1e4+3;
const long long INF=(long long)(1e18);

vector<Edge> graph[MAXN];
int parent[2][MAXN];
long long dist[2][MAXN];

void calc_dist(int startp, int type, int n){
    for(int i=0;i<n;++i){
        dist[type][i]=INF;
        parent[type][i]=-1;
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> dijkstra;
    dijkstra.push({0, startp});
    dist[type][startp]=0;

    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();
        
        for(Edge nextv : graph[currv]){
            if(type==0 and nextv.is_dirty){
                continue;
            }

            long long new_dist=dist[type][currv]+nextv.len;

            if(dist[type][nextv.to]>new_dist){
                dist[type][nextv.to]=new_dist;
                parent[type][nextv.to]=currv;
                dijkstra.push({dist[type][nextv.to], nextv.to});
            }
        }
    }

    // Double the time of the tortoise
    if(type==1){
        for(int i=0;i<n;++i){
            if(dist[type][i]!=INF){
                dist[type][i]*=2;
            }
        }
    }
}

int intersections(int startp, int endp){
    int res=0;
    int rabbit=parent[0][endp],tortoise=parent[1][endp];

    while(rabbit!=startp and tortoise!=startp){
        if(dist[0][rabbit]==dist[1][tortoise]){
            ++res;
            rabbit=parent[0][rabbit];
            tortoise=parent[1][tortoise];
        }else if(dist[0][rabbit]>dist[1][tortoise]){
            rabbit=parent[0][rabbit];
        }else{
            tortoise=parent[1][tortoise];
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int from,to,len,type;
        cin>>from>>to>>len>>type;
        --from;
        --to;

        graph[from].push_back(Edge(to, len, type==2));
        graph[to].push_back(Edge(from, len, type==2));
    }

    int startp,endp;
    cin>>startp>>endp;
    --startp;
    --endp;

    calc_dist(startp, 0, n);
    calc_dist(startp, 1, n);

    if(dist[0][endp]==dist[1][endp]){
        cout<<"Tie\n";
    }else{
        cout<<(dist[0][endp]>dist[1][endp] ? "Tortoise" : "Rabbit")<<endl;
    }
    cout<<min(dist[0][endp], dist[1][endp])<<endl;
    cout<<intersections(startp, endp)<<endl;
return 0;
}