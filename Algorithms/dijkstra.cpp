#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1005,INF=1<<30;
int dist[MAXN],weight[MAXN][MAXN];
vector<pair<int,int>> graph[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){                                                                                                                                        
        int from,to,weight;
        cin>>from>>to>>weight;
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }

    int start_point;
    cin>>start_point;
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[start_point]=0;

    priority_queue<pair<int,int>> dijkstra;
    dijkstra.push({0,start_point});

    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();
        for(pair<int,int> nextv : graph[currv]){
            if(dist[currv]+nextv.second<dist[nextv.first]){
                dist[nextv.first]=dist[currv]+nextv.second;
                dijkstra.push({-dist[nextv.first],nextv.first});
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
return 0;
}
