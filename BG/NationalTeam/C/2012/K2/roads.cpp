#include<iostream>
#include<queue>
#include<utility>
#include<string>
#define endl '\n'
using namespace std;
const int MAXN=103,INF=1e8,MOD=1000000009;
pair<int,int> dirs[4]={{0,-1},{0,1},{-1,0},{1,0}};
char map[MAXN][MAXN];
int dist[MAXN][MAXN];
long long counter[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    pair<int,int> startp,endp;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>map[i][i2];
            if(map[i][i2]=='E'){
                startp={i,i2};
            }else if(map[i][i2]=='X'){
                endp={i,i2};
            }
            dist[i][i2]=INF;
        }
    }
    queue<pair<int,int>> bfs;
    bfs.push(startp);
    dist[startp.first][startp.second]=0;
    counter[startp.first][startp.second]=1;
    while(!bfs.empty()){
        pair<int,int> curr=bfs.front();
        bfs.pop();
        for(int i=0;i<4;++i){
            int nextx=curr.first+dirs[i].first,nexty=curr.second+dirs[i].second;
            if(nextx>=0 and nextx<n and nexty>=0 and nexty<m and map[nextx][nexty]!='#'){
                int curr_dist=dist[curr.first][curr.second]+1;
                if(curr_dist<dist[nextx][nexty]){
                    if(dist[nextx][nexty]==INF){
                        bfs.push({nextx,nexty});
                    }
                    dist[nextx][nexty]=curr_dist;
                    counter[nextx][nexty]=counter[curr.first][curr.second];
                }else if(curr_dist==dist[nextx][nexty]){
                    counter[nextx][nexty]=(counter[nextx][nexty]+counter[curr.first][curr.second])%MOD;
                }
            }
        }
    }
    cout<<counter[endp.first][endp.second]<<endl;
return 0;
}