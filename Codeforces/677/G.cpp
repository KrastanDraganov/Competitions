#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<functional>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,INF=1e9+3;
vector<pair<int, int>> graph[MAXN];
pair<int, int> queries[MAXN];
int dist[MAXN][MAXN];

void calc_dijkstra(int startp, int n){
    for(int i=0;i<n;++i){
        dist[startp][i]=INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra;
    dijkstra.push({0, startp});
    dist[startp][startp]=0;

    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();

        for(pair<int, int> nextv : graph[currv]){
            int new_dist=dist[startp][currv]+nextv.second;
            if(dist[startp][nextv.first]>new_dist){
                dist[startp][nextv.first]=new_dist;
                dijkstra.push({dist[startp][nextv.first], nextv.first});
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
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    for(int i=0;i<k;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        queries[i]={from, to};
    }

    for(int i=0;i<n;++i){
        calc_dijkstra(i, n);
    }

    int res=INF;
    for(int cut1=0;cut1<n;++cut1){
        for(pair<int, int> nextv : graph[cut1]){
            int cut2=nextv.first;

            int curr=0;
            for(int i=0;i<k;++i){
                int from=queries[i].first;
                int to=queries[i].second;
                curr+=min({dist[from][to], dist[from][cut1]+dist[cut2][to],
                            dist[from][cut2]+dist[cut1][to]});
            }
            res=min(res, curr);
        }
    }

    cout<<res<<endl;
return 0;
}