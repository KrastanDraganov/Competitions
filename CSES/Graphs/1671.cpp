#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
const long long INF=(long long)(1e18);
vector<pair<int, int>> graph[MAXN];
long long dist[MAXN];
bool visited[MAXN];

void find_shortest_paths(int n){
    for(int i=0;i<n;++i){
        dist[i]=INF;
    }

    priority_queue<pair<long long, int>> dijkstra;
    dijkstra.push({0, 0});
    dist[0]=0;
    
    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();

        if(visited[currv]){
            continue;
        }
        visited[currv]=true;

        for(pair<int, int> nextv : graph[currv]){
            long long new_dist=dist[currv]+nextv.second;
            if(new_dist<dist[nextv.first]){
                dist[nextv.first]=new_dist;
                dijkstra.push({-new_dist, nextv.first});
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
        graph[from].push_back({to, weight});
    }

    find_shortest_paths(n);

    for(int i=0;i<n;++i){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
return 0;
}