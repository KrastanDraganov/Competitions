#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=250;
vector<pair<int,int>> graph[MAXN];
pair<pair<int,int>,int> edges[MAXN];
long long dist[2][MAXN];

void calc_dijkstra(int startp, int type){
    priority_queue<pair<long long,int>> dijkstra;
    dijkstra.push({0,startp});
    dist[type][startp]=0;
    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();
        for(pair<int,int> nextv : graph[currv]){
            long long new_dist=dist[type][currv]+nextv.second;
            if(new_dist<dist[type][nextv.first]){
                dist[type][nextv.first]=new_dist;
                dijkstra.push({-new_dist,nextv.first});
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
        int from,to,weight;
        cin>>from>>to>>weight;
        --from;
        --to;
        edges[i]={{from,to},weight};
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }
}