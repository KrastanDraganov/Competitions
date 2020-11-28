#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<functional>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<pair<int, int>> graph[MAXN];
int visited[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<m;++i){
        int from,to,price;
        cin>>from>>to>>price;
        --from;
        --to;
        graph[from].push_back({to, price});
    }

    priority_queue<pair<long long, int>,
                    vector<pair<long long, int>>,
                    greater<pair<long long, int>>> dijkstra;
    dijkstra.push({0, 0});
    ++visited[0];

    vector<long long> shortest_flights;
    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        long long curr_dist=dijkstra.top().first;
        dijkstra.pop();
        
        if(visited[currv]>k){
            continue;
        }
        ++visited[currv];

        if(currv==n-1){
            shortest_flights.push_back(curr_dist);
            if(visited[currv]==k){
                break;
            }
        }

        for(pair<int, int> nextv : graph[currv]){
            if(visited[nextv.first]<=k){
                dijkstra.push({curr_dist+nextv.second, nextv.first});
            }
        }
    }

    for(long long dist : shortest_flights){
        cout<<dist<<" ";
    }
    cout<<endl;
return 0;
}