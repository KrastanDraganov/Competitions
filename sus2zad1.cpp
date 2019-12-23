#include<bits/stdc++.h>
using namespace std;
const int INF=1<<30,N=20002,START_POINT=0;
int dist[N];
vector<int>graph[N],passengers[N];
priority_queue<pair<int,int>>deijkstra;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        passengers[a].push_back(c);
        passengers[b].push_back(c);
    }
    //for(int i=0;i<n;i++) dist[i]=INF;
        for(int i=0;i<n;i++) dist[i]=0;
        dist[START_POINT]=INF;
        deijkstra.push({0,START_POINT});
        while(!deijkstra.empty()){
            int cur=deijkstra.top().second;
            deijkstra.pop();
            for(int i=0;i<graph[cur].size();i++){
                int d=graph[cur][i];
                int p=passengers[cur][i];
                //cout<<cur<<" "<<d<<" "<<p<<" "<<dist[cur]<<" "<<dist[d]<<endl;
                if(min(dist[cur],p)>dist[d]){
                    dist[d]=min(dist[cur],p);
                    deijkstra.push({-dist[d],d});
                }
            }
        }
    for(int i=1;i<n;i++) cout<<dist[i]<<" ";
    cout<<endl;
return 0;
}
