#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=63;
pair<int,int> dirs[4]={{0,-1},{0,1},{-1,0},{1,0}};
bool removed[MAXN][MAXN],visited[MAXN][MAXN];

void dfs(int x, int y, int n, int m){
    visited[x][y]=true;
    for(int i=0;i<4;++i){
        int nextx=x+dirs[i].first;
        int nexty=y+dirs[i].second;
        if(nextx>=0 and nextx<n and nexty>=0 and nexty<m){
            if(!visited[nextx][nexty] and !removed[nextx][nexty]){
                dfs(nextx,nexty,n,m);
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
        int cutx,cuty;
        cin>>cutx>>cuty;
        --cutx;
        --cuty;
        removed[cutx][cuty]=true;
    }

    int res=0;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            if(!removed[i][i2] and !visited[i][i2]){
                dfs(i,i2,n,m);
                ++res;
            }
        }
    }
    cout<<res<<endl;
return 0;
}