#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<pair<int,int>> graph[2][MAXN];
pair<pair<int,int>,int> edges[MAXN];
long long dist[2][MAXN],paths[2][MAXN];

void calc_dijkstra(int startp, int type){
    priority_queue<pair<long long,int>> dijkstra;
    dijkstra.push({0,startp});
    dist[type][startp]=0;
    paths[type][startp]=1;
    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();
        for(pair<int,int> nextv : graph[type][currv]){
            long long new_dist=dist[type][currv]+nextv.second;
            if(new_dist<dist[type][nextv.first]){
                dist[type][nextv.first]=new_dist;
                paths[type][nextv.first]=paths[type][currv];
                dijkstra.push({-new_dist,nextv.first});
            }else if(new_dist==dist[type][nextv.first]){
                paths[type][nextv.first]+=paths[type][currv];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s,t;
    cin>>n>>m>>s>>t;
    --s;
    --t;
    for(int i=0;i<m;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        --from;
        --to;
        edges[i]={{from,to},weight};
        graph[0][from].push_back({to,weight});
        graph[1][to].push_back({from,weight});
    }

    for(int i=0;i<n;++i){
        for(int type=0;type<2;++type){
            dist[type][i]=1e17;
            paths[type][i]=0;
        }
    }
    calc_dijkstra(s,0);
    calc_dijkstra(t,1);
    
    cout<<"kzl: "<<dist[0][t]<<" "<<paths[0][t]<<endl;
    for(int i=0;i<m;++i){
        pair<int,int> curr=edges[i].first;
        int weight=edges[i].second;
        if(dist[0][curr.first]+weight+dist[1][curr.second]!=dist[0][t]){
            cout<<"NO\n";
        }else if(paths[0][curr.first]*paths[1][curr.second]==paths[0][t]){
            cout<<"YES\n";
        }else{
            int res=dist[0][t]-dist[0][curr.first]-dist[1][curr.second]-1;
            cout<<res<<endl;
            if(res>0){
                cout<<"CAN "<<res<<endl;
            }else{
                cout<<"brum NO\n";
            }
        }
    }
return 0;
}