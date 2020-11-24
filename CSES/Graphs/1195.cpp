#include<iostream>
#include<queue>
#include<vector>
#include<functional>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
const long long INF=(long long)(1e18);
vector<pair<int, int>> graph[2][MAXN];
long long dist[2][MAXN];
bool visited[2][MAXN];

void calc_dist(int startv, int type){
    priority_queue<pair<long long, int>, 
                vector<pair<long long, int>>, 
                greater<pair<long long, int>>> dijkstra;
    dijkstra.push({0, startv});
    dist[type][startv]=0;

    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();

        if(visited[type][currv]){
            continue;
        }
        visited[type][currv]=true;

        for(pair<int, int> nextv : graph[type][currv]){
            long long new_dist=dist[type][currv]+nextv.second;
            if(new_dist<dist[type][nextv.first]){
                dist[type][nextv.first]=new_dist;
                dijkstra.push({new_dist, nextv.first});
            }
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

        graph[0][from].push_back({to, price});
        graph[1][to].push_back({from, price});
    }

    for(int i=0;i<2;++i){
        for(int i2=0;i2<n;++i2){
            dist[i][i2]=INF;
        }
    }
    calc_dist(0, 0);
    calc_dist(n-1, 1);

    long long res=dist[0][n-1];
    for(int currv=0;currv<n;++currv){
        for(pair<int, int> nextv : graph[0][currv]){
            res=min(res, dist[0][currv]+(nextv.second/2)+dist[1][nextv.first]);
        }
    }

    cout<<res<<endl;
return 0;
}