#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=101,INF=2e9;
vector<pair<int,int>> graph[MAXN];
int dist[MAXN][MAXN];
priority_queue<pair<int,pair<int,int>>> dijkstra;

int calc_dijkstra(int a, int b, int k){
    dist[0][0]=0;
    dijkstra.push({0,{a,0}});
    while(!dijkstra.empty()){
        int cd=dijkstra.top().first*(-1);
        int curr=dijkstra.top().second.first;
        int counter=dijkstra.top().second.second;
        dijkstra.pop();
        if(curr==b and counter==k){
            return cd;
        }
        if(cd>dist[curr][counter]){
            continue;
        }
        for(pair<int,int> next : graph[curr]){
            if(dist[next.first][counter+1]>cd+next.second){
                dist[next.first][counter+1]=cd+next.second;
                dijkstra.push({-dist[next.first][counter+1],{next.first,counter+1}});
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,k,a,b;
    cin>>n>>m>>k>>a>>b;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back({y,z});
    }
    
    for(int i=0;i<n;i++){
        for(int i2=0;i2<n;i2++){
            dist[i][i2]=INF;
        }
    }
    
    cout<<calc_dijkstra(a,b,k)<<endl;
return 0;
}