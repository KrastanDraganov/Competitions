#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

struct Edge {
    int to,time,price;
    Edge(int _to=-1, int _time=0, int _price=0){
        to=_to;
        time=_time;
        price=_price;
    }
};

const int MAXN=3e3+3,MAXS=2e+3,INF=1e9;
vector<Edge> graph[MAXN];
int dist[MAXN][MAXS];
bool in_queue[MAXN][MAXS];

int min_time(int n, int s){
    for(int i=0;i<n;++i){
        for(int i2=0;i2<=s;++i2){
            dist[i][i2]=INF;
        }
    }

    queue<pair<int, int>> spfa;
    spfa.push({0, 0});
    dist[0][0]=0;
    in_queue[0][0]=true;

    while(!spfa.empty()){
        pair<int, int> currv=spfa.front();
        spfa.pop();
        in_queue[currv.first][currv.second]=false;

        for(Edge nextv : graph[currv.first]){
            int new_price=currv.second+nextv.price;
            if(new_price>s){
                continue;
            }

            int new_dist=dist[currv.first][currv.second]+nextv.time;
            if(new_dist<dist[nextv.to][new_price]){
                dist[nextv.to][new_price]=new_dist;
                if(!in_queue[nextv.to][new_price]){
                    in_queue[nextv.to][new_price]=true;
                    spfa.push({nextv.to, new_price});
                }
            }
        }
    }

    int res=INF;
    for(int i=0;i<=s;++i){
        res=min(res, dist[n-1][i]);
    }

    return (res==INF ? -1 : res);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s,n,m;
    cin>>s>>n>>m;

    for(int i=0;i<m;++i){
        int from,to,time,price;
        cin>>from>>to>>time>>price;
        --from;
        --to;
        graph[from].push_back(Edge(to, time, price));
        graph[to].push_back(Edge(from, time, price));
    }

    cout<<min_time(n, s)<<endl;
return 0;
}