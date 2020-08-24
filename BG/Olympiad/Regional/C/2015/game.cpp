#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<math.h>

#define endl '\n'

using namespace std;

const int MAXN=2e4+3,INF=1e9;
int dist[MAXN];
vector<pair<int,int>> graph[MAXN];
priority_queue<pair<int,int>> dijkstra;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,p,t;
        cin>>a>>b>>p>>t;
        graph[a].push_back({b,fabs(p-t)});
        graph[b].push_back({a,fabs(p-t)});
    }
    
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    
    dist[1]=0;
    dijkstra.push({0,1});
    while(!dijkstra.empty()){
        int curr=dijkstra.top().second;
        dijkstra.pop();
        for(int i=0;i<graph[curr].size();i++){
            int d=graph[curr][i].first,cp=graph[curr][i].second;
            if(dist[curr]+cp<dist[d]){
                dist[d]=dist[curr]+cp;
                dijkstra.push({-dist[d],d});
            }
        }
    }
    cout<<k-dist[n]<<endl;
return 0;
}
