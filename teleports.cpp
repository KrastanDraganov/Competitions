#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN = 1e3+2;
int price[MAXN][MAXN];
vector<pair<int,int>> graph[MAXN][MAXN];
int calc_bfs(int startx, int starty, int endx, int endy){
    queue<pair<int,int>> bfs;
    bfs.push({startx,starty});
    price[startx][starty]=0;
    while(!bfs.empty()){
        pair<int,int> curr=bfs.front();
        bfs.pop();
        if(curr.first==endx and curr.second==endy){
            return price[endx][endy];
        }
        for(pair<int,int> next : graph[curr.first][curr.second]){
            if(price[next.first][next.second]==0){
                price[next.first][next.second]=price[curr.first][curr.second]+10;
                bfs.push(next);
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int startx,starty,endx,endy,n;
    cin>>startx>>starty>>endx>>endy>>n;
    for(int i=0;i<n;++i){
        int fromx,fromy,tox,toy;
        cin>>fromx>>fromy>>tox>>toy;
        graph[fromx][fromy].push_back({tox,toy});
        graph[tox][toy].push_back({fromx,fromy});
    }
    int ans=calc_bfs(startx,starty,endx,endy);
    if(ans==-1){
        cout<<"no solution\n";
    }else{
        cout<<ans<<endl;
    }
return 0;
}