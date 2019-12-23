#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define MAXN 1010
using namespace std;
const long long INF = 1e18;
int m,n;
pair<int,int> dirs[]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{-1,-1}};
pair<int,int> dirs2[]={{-1,0},{1,0},{0,-1},{0,1},{1,-1},{1,1}};
long long tiles[MAXN][MAXN],visited[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    for(int i=0;i<n;++i){   
        bool one_more=(i%2==1);
        for(int i2=0;i2<m+(int)one_more;++i2){
            cin>>tiles[i2][i];
            //cout<<i2<<" "<<i<<" "<<tiles[i2][i]<<endl;
        }
    }
    ++m;
    priority_queue<pair<long long,pair<int,int>>> dijkstra;
    for(int i=0;i<n;++i){
        dijkstra.push({(-1)*abs(tiles[0][i]),{0,i}});
    }
    while(!dijkstra.empty()){
        pair<long long,pair<int,int>> curr=dijkstra.top();
        dijkstra.pop();
        long long currdist=curr.first;
        int currx=curr.second.first,curry=curr.second.second;
        //cout<<currx<<" "<<curry<<" "<<(-1)*currdist<<endl;
        if(currx==-69 and curry==-69){
            cout<<(-1)*currdist<<endl;
            break;
        }
        if(visited[currx][curry]){
            continue;
        }
        visited[currx][curry]=true;
        for(int i=0;i<6;++i){
            int newx,newy;
            if(curry%2==0){
                newx=currx+dirs2[i].first;
                newy=curry+dirs2[i].second;
            }else{
                newx=currx+dirs[i].first;
                newy=curry+dirs[i].second;
            }
            if(newx>=0 and newy>=0 and newx<m and newy<n){
                if(!visited[newx][newy]){
                    dijkstra.push({(-1)*((-1)*currdist+abs(tiles[currx][curry]-tiles[newx][newy])),{newx,newy}});
                }
            }else if(newx==m){
                dijkstra.push({(-1)*((-1)*currdist+abs(tiles[newx][newy])),{-69,-69}});
            }
        }
    }
return 0;
}