#include<iostream>
#include<utility>
#include<queue>
#define endl '\n'
#define MAXN 103
using namespace std;
pair<int,int> dirs[4]={{0,-1},{0,1},{-1,0},{1,0}};
char maze[MAXN][MAXN];
int dist[MAXN][MAXN][2];
int sol(pair<int,int> startp, int n, int m){
    queue<pair<pair<int,int>,bool>> bfs;
    bfs.push({startp,false});
    while(!bfs.empty()){
        pair<int,int> curr=bfs.front().first;
        bool bomb=bfs.front().second;
        bfs.pop();
        for(pair<int,int> next : dirs){
            int nextx=curr.first+next.first,nexty=curr.second+next.second;
            if(nextx>=0 and nextx<n and nexty>=0 and nexty<m){
                if(maze[nextx][nexty]=='.' and !dist[nextx][nexty][bomb]){
                    dist[nextx][nexty][bomb]=dist[curr.first][curr.second][bomb]+1;
                    bfs.push({{nextx,nexty},bomb});
                }else if(maze[nextx][nexty]=='#' and !bomb){
                    dist[nextx][nexty][1]=dist[curr.first][curr.second][0]+3;
                    bfs.push({{nextx,nexty},true});
                }else if(maze[nextx][nexty]=='E'){
                    return dist[curr.first][curr.second][bomb]+1;
                }
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    pair<int,int> startp;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>maze[i][i2];
            if(maze[i][i2]=='B'){
                startp={i,i2};
            }
        }
    }
    cout<<sol(startp,n,m)<<endl;
return 0;
}