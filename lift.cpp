#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN=1e6+3;
bool is_lift[MAXN];
vector<pair<int,int>> graph[2*MAXN];
int dist[2*MAXN];
int res(int n){
    for(int i=2;i<2*MAXN;++i){
        dist[i]=1e9+3;
    }
    dist[1]=0;
    priority_queue<pair<int,int>> dijkstra;
    dijkstra.push({0,1});
    while(!dijkstra.empty()){
        int curr=dijkstra.top().second;
        dijkstra.pop();
        if(curr==n){
            return dist[n];
        }
        for(pair<int,int> next : graph[curr]){
            if(dist[curr]+next.second<dist[next.first]){
                dist[next.first]=dist[curr]+next.second;
                dijkstra.push({-dist[next.first],next.first});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,u,d,inp,j,l;
    cin>>n>>u>>d>>inp>>j>>l;
    int counter=1,last,max_floor=n;
    for(int i=0;i<l;++i){
        int k;
        cin>>k;
        last=0;
        for(int i2=0;i2<k;++i2){
            int floor,vertex=1e6+1+counter;
            cin>>floor;
            max_floor=max(max_floor,floor);
            is_lift[floor]=true;
            ++counter;
            graph[vertex].push_back({floor,j});
            graph[floor].push_back({vertex,inp});
            if(i2>0){
                graph[last].push_back({vertex,0});
                graph[vertex].push_back({last,0});
            }
            last=vertex;
        }
    }
    last=1;
    for(int i=2;i<=max_floor;++i){
        if(is_lift[i] or i==n or i==max_floor){
            graph[last].push_back({i,(i-last)*u});
            graph[i].push_back({last,(i-last)*d});
            last=i;
        }
    }
    cout<<res(n)<<endl;
return 0;
}