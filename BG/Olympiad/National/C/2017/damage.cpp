#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

const int MAXN=1e3+3;
const long long INF = 1e18;
pair<int,int> dirs[]={{-1,0},{1,0},{0,-1},{0,1},{1,-1},{-1,-1}};
pair<int,int> dirs2[]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,1}};
long long tiles[MAXN][MAXN],dist[MAXN][MAXN];

long long calc_dijkstra(int n, int m){
    for(int i=0;i<MAXN;++i){
        for(int i2=0;i2<MAXN;++i2){
            dist[i][i2]=INF;
        }
    }
    
    priority_queue<pair<long long,pair<int,int>>> dijkstra;
    for(int i=0;i<n;++i){
        dist[i][0]=abs(tiles[i][0]);
        if(i%2==0 and m==1){
            dijkstra.push({-(2*dist[i][0]),{-69,-69}});
        }else{
            dijkstra.push({-dist[i][0],{i,0}});
        }
    }
    
    while(!dijkstra.empty()){
        pair<int,int> curr=dijkstra.top().second;
        if(curr.first==-69 and curr.second==-69){
            return -dijkstra.top().first;
        }
        dijkstra.pop();
        
        for(int i=0;i<6;++i){
            int newx=curr.first,newy=curr.second;
            
            if(curr.first%2==1){
                newx+=dirs[i].first;
                newy+=dirs[i].second;
            }else{
                newx+=dirs2[i].first;
                newy+=dirs2[i].second;
            }
            
            if(newx>=0 and newx<n and newy>=0 and ((newx%2==0 and newy<m) or (newx%2==1 and newy<=m))){
                long long curr_dist=dist[curr.first][curr.second]+abs(tiles[curr.first][curr.second]-tiles[newx][newy]);
                if(curr_dist<dist[newx][newy]){
                    dist[newx][newy]=curr_dist;
                    if((newx%2==0 and newy==m-1) or (newx%2==1 and newy==m)){
                        dijkstra.push({-(dist[newx][newy]+abs(tiles[newx][newy])),{-69,-69}});
                    }else{
                        dijkstra.push({-dist[newx][newy],{newx,newy}});
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;++i){   
        bool one_more=(i%2==1);
        for(int i2=0;i2<m+(int)one_more;++i2){
            cin>>tiles[i][i2];
        }
    }
    
    cout<<calc_dijkstra(n,m)<<endl;
return 0;
}