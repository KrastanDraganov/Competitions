#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
const long long INF=1e17;
long long tech_map[645][645],dist[645][645];
pair<int,int> dirs[]={{0,-1},{0,1},{-1,0},{1,0}};
priority_queue<pair<int,pair<int,int>>> dijkstra;
vector<pair<int,int>> possible;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,startx,starty;
    cin>>n>>m;
    char input;
    for(int i=0;i<n;i++){
        for(int i2=0;i2<m;i2++){
            cin>>input;
            if(input=='#'){
                startx=i;
                starty=i2;
            }
            if(input>='A' and input<='Z'){
                tech_map[i][i2]=input-'A'+1;
            }else{
                tech_map[i][i2]=0;
            }
            dist[i][i2]=INF;
        }
    }
    dist[startx][starty]=0;
    dijkstra.push({0,{startx,starty}});
    while(!dijkstra.empty()){
        int currx=dijkstra.top().second.first,curry=dijkstra.top().second.second;
        dijkstra.pop();
        for(int i=0;i<4;++i){
            int nextx=currx+dirs[i].first,nexty=curry+dirs[i].second;
            if(nextx>-1 and nexty>-1){
                if(tech_map[nextx][nexty]>0 and dist[currx][curry]+tech_map[nextx][nexty]<dist[nextx][nexty]){
                    dist[nextx][nexty]=dist[currx][curry]+tech_map[nextx][nexty];
                    if(nextx==0 or nexty==0 or nextx==n-1 or nexty==m-1){
                        possible.push_back({nextx,nexty});
                    }
                    dijkstra.push({-dist[nextx][nexty],{nextx,nexty}});
                }
            }
        }
    }
    long long res=1e18;
    for(int i=0;i<possible.size();i++){
        long long curr_res=dist[possible[i].first][possible[i].second];
        res=min(res,curr_res);
    }
    cout<<res<<endl;
return 0;
}