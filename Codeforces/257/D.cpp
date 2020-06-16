#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<pair<pair<int,int>,int>> graph[MAXN];
long long dist[MAXN];
bool visited[MAXN];

void calc_dijkstra(int startp, int& res){
    priority_queue<pair<pair<long long,int>,int>> dijkstra;
    dijkstra.push({{0,0},startp});
    dist[startp]=0;
    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        int type=dijkstra.top().first.second;
        dijkstra.pop();
        if(visited[currv]){
            continue;
        }
        visited[currv]=true;
        if(type==-1){
            --res;
        }
        for(pair<pair<int,int>,int> nextv : graph[currv]){
            long long new_dist=dist[currv]+nextv.first.second;
            if(new_dist<=dist[nextv.first.first]){
                dist[nextv.first.first]=new_dist;
                dijkstra.push({{-new_dist,-nextv.second},nextv.first.first});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        --from;
        --to;
        graph[from].push_back({{to,weight},0});
        graph[to].push_back({{from,weight},0});
    }
    for(int i=0;i<k;++i){
        int target,weight;
        cin>>target>>weight;
        --target;
        graph[0].push_back({{target,weight},1});
        graph[target].push_back({{0,weight},1});
    }

    for(int i=0;i<n;++i){
        dist[i]=1e17;
    }
    int res=k;
    calc_dijkstra(0,res);
    cout<<res<<endl;
return 0;
}