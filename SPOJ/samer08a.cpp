#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=503,INF=1e9;
vector<pair<int,int>> graph[2][MAXN];
int dist[2][MAXN];
bool is_cut[MAXN][MAXN];

void calc_dijkstra(int startp, int type){
    priority_queue<pair<int,int>> dijkstra;
    dijkstra.push({0,startp});
    dist[type][startp]=0;
    while(!dijkstra.empty()){
        int currv=dijkstra.top().second;
        dijkstra.pop();
        for(pair<int,int> nextv : graph[type][currv]){
            int new_dist=dist[type][currv]+nextv.second;
            if(!is_cut[currv][nextv.first] and new_dist<dist[type][nextv.first]){
                dist[type][nextv.first]=new_dist;
                dijkstra.push({-new_dist,nextv.first});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    while(cin>>n>>m){
        if(n==0 and m==0){
            break;
        }
        for(int i=0;i<n;++i){
            for(int type=0;type<2;++type){
                graph[type][i].clear();
                dist[type][i]=INF;
            }
        }
        
        int startp,endp;
        cin>>startp>>endp;
        for(int i=0;i<m;++i){
            int from,to,weight;
            cin>>from>>to>>weight;
            is_cut[from][to]=false;
            is_cut[to][from]=false;
            graph[0][from].push_back({to,weight});
            graph[1][to].push_back({from,weight});
        }

        calc_dijkstra(startp,0);
        calc_dijkstra(endp,1);
        int target=dist[0][endp];
        for(int currv=0;currv<n;++currv){
            for(pair<int,int> nextv : graph[0][currv]){
                if(dist[0][currv]+dist[1][nextv.first]+nextv.second==target){
                    is_cut[currv][nextv.first]=true;
                }
            }
        }
        
        for(int i=0;i<n;++i){
            dist[0][i]=INF;
        }
        calc_dijkstra(startp,0);
        cout<<(dist[0][endp]==INF ? -1 : dist[0][endp])<<endl;
    }
return 0;
}