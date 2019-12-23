#include<bits/stdc++.h>
using namespace std;
const int INF=1<<30,N=1005;
int dist[1005],weight[N][N];
vector<int>graph[N];
priority_queue<pair<int,int>>deijkstra;
int main(){
    int n,m,start_point;
    cin>>n>>m;
    for(int i=0;i<m;i++){                                                                                                                                        
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        weight[a][b]=c;
        weight[b][a]=c;
    }
    cin>>start_point;
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[start_point]=0;
    deijkstra.push({0,start_point});
    while(!deijkstra.empty()){
        int curr=deijkstra.top().second;
        deijkstra.pop();
        for(int i=0;i<graph[curr].size();i++){
            int d=graph[curr][i],w=weight[curr][graph[curr][i]];
            if(dist[curr]+w<dist[d]){
                dist[d]=dist[curr]+w;
                deijkstra.push({-dist[d],d});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
return 0;
}
