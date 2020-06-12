#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<pair<int,int>> graph[MAXN];
long long dist[MAXN];
pair<int,int> special[MAXN];

void calc_dijkstra(int startp){
    priority_queue<pair<long long,int>> dijkstra;
    dijkstra.push({0,startp});
    dist[startp]=0;
    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();
        for(pair<int,int> nextv : graph[currv]){
            long long new_dist=dist[currv]+nextv.second;
            if(new_dist<dist[nextv.first]){
                dist[nextv.first]=new_dist;
                dijkstra.push({-new_dist,nextv.first});
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
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }
    for(int i=0;i<k;++i){
        int target,weight;
        cin>>target>>weight;
        --target;
        special[i]={target,weight};
        graph[0].push_back({target,weight});
        graph[target].push_back({0,weight});
    }

    for(int i=0;i<n;++i){
        dist[i]=1e17;
    }
    calc_dijkstra(0);
    
    int res=0;
    for(int i=0;i<k;++i){
        int currv=special[i].first;
        bool check=false;
        for(pair<int,int> nextv : graph[currv]){
            if(!check and nextv.first==0 and nextv.second==special[i].second){
                check=true;
                continue;
            }
            if(dist[nextv.first]+nextv.second==dist[currv]){
                ++res;
                break;
            }
        }
    }
    cout<<res<<endl;
return 0;
}