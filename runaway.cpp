//O(N*N*logN)
#include<iostream>
#include<queue>
#include<utility>
#include<unordered_map>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
pair<int,int> dirs[4]={{0,-1},{0,1},{-1,0},{1,0}};
int table[MAXN][MAXN],dist[MAXN][MAXN];
unordered_map<int,int> min_dist;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cin>>table[i][i2];
        }
    }

    queue<pair<int,int>> bfs;
    bfs.push({0,n-1});
    dist[0][n-1]=1;
    min_dist[table[0][n-1]]=1;
    while(!bfs.empty()){
        pair<int,int> currv=bfs.front();
        bfs.pop();
        for(int i=0;i<4;++i){
            int nextx=currv.first+dirs[i].first;
            int nexty=currv.second+dirs[i].second;
            if(nextx>=0 and nextx<n and nexty>=0 and nexty<n){
                if(!dist[nextx][nexty]){
                    dist[nextx][nexty]=dist[currv.first][currv.second]+1;
                    int next_room=table[nextx][nexty];
                    if(min_dist.find(next_room)==min_dist.end()){
                        min_dist[next_room]=dist[nextx][nexty];
                    }else{
                        min_dist[next_room]=min(min_dist[next_room],dist[nextx][nexty]);
                    }
                    bfs.push({nextx,nexty});
                }
            }
        }
    }

    int q;
    cin>>q;
    while(q--){
        int exit;
        cin>>exit;
        if(min_dist.find(exit)==min_dist.end()){
            cout<<"No Solution\n";
        }else{
            cout<<min_dist[exit]-1<<endl;
        }
    }
return 0;
}