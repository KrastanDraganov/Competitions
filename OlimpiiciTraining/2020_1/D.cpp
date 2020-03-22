#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
vector<pair<int,int>> graph[MAXN];
int dist[6][MAXN];
pair<int,int> markets[6];
bool is_market[MAXN];

void calc_dijkstra(int ind){
    priority_queue<pair<int,int>> dijkstra;
    dijkstra.push({0,markets[ind].first});
    dist[ind][markets[ind].first]=0;
    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();
        for(pair<int,int> nextv : graph[currv]){
            int curr_dist=dist[ind][currv]+nextv.second;
            if(curr_dist<dist[ind][nextv.first]){
                dist[ind][nextv.first]=curr_dist;
                dijkstra.push({-curr_dist,nextv.first});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;++i){
        int market;
        cin>>market;
        is_market[market]=true;
        markets[i]={market-1,i};
    }
    for(int i=0;i<m;++i){
        int from,to,length;
        cin>>from>>to>>length;
        --from;
        --to;
        graph[from].push_back({to,length});
        graph[to].push_back({from,length});
    }
    for(int i=0;i<k;++i){
        for(int i2=0;i2<MAXN;++i2){
            dist[i][i2]=1e9;
        }
        calc_dijkstra(i);
    }
    int res=1e9;
    for(int i=0;i<n;++i){
        sort(markets,markets+k);
        if(!is_market[i]){
            do{
                int curr=dist[markets[0].second][i];
                for(int i=0;i<k-1;++i){
                    curr+=dist[markets[i].second][markets[i+1].second];
                }
                curr+=dist[markets[k-1].second][i];
                res=min(res,curr);
            }while(next_permutation(markets,markets+k));
        }
    }
    cout<<res<<endl;
return 0;
}
