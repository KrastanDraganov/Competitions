#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
pair<int, int> dirs[4]={{0,-1}, {0,1}, {-1,0}, {1,0}};
bool visited[MAXN][MAXN];

bool is_free(int x, int y, int n, int m){
    return x>=0 and x<n and y>=0 and y<m and !visited[x][y];
}

void dfs(int currx, int curry, int n, int m){
    visited[currx][curry]=true;
    
    for(int i=0;i<4;++i){
        int nextx=currx+dirs[i].first;
        int nexty=curry+dirs[i].second;
        
        if(is_free(nextx, nexty, n, m)){
            dfs(nextx, nexty, n, m);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            char curr;
            cin>>curr;
            if(curr=='#'){
                visited[i][i2]=true;
            }
        }
    }

    int rooms=0;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            if(!visited[i][i2]){
                dfs(i, i2, n, m);
                ++rooms;
            }
        }
    }

    cout<<rooms<<endl;
return 0;
}