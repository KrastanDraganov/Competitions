#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=1e3+3;
pair<int, int> dirs[4]={{0,-1}, {0,1}, {-1,0}, {1,0}};
string letters="LRUD";
char which_dir[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];
int dist[2][MAXN][MAXN];
 
bool is_free(int x, int y, int type, int n, int m){
    return x>=0 and x<n and y>=0 and y<m and dist[type][x][y]==-1;
}
 
void calc_monsters(vector<pair<int, int>>& monsters, int n, int m){
    queue<pair<int, int>> bfs;
    for(pair<int, int> curr : monsters){
        bfs.push(curr);
        dist[1][curr.first][curr.second]=0;
    }
 
    while(!bfs.empty()){
        pair<int, int> currp=bfs.front();
        bfs.pop();
 
        for(int i=0;i<4;++i){
            int nextx=currp.first+dirs[i].first;
            int nexty=currp.second+dirs[i].second;
 
            if(is_free(nextx, nexty, 1, n, m)){
                dist[1][nextx][nexty]=dist[1][currp.first][currp.second]+1;
                bfs.push({nextx, nexty});
            }
        }
    }
}
 
void calc_player(pair<int, int> startp, int n, int m){
    dist[0][startp.first][startp.second]=0;
    which_dir[startp.first][startp.second]='A';
    parent[startp.first][startp.second]={-1, -1};
 
    queue<pair<int, int>> bfs;
    bfs.push(startp);
 
    while(!bfs.empty()){
        pair<int, int> currp=bfs.front();
        bfs.pop();
 
        for(int i=0;i<4;++i){
            int nextx=currp.first+dirs[i].first;
            int nexty=currp.second+dirs[i].second;
 
            if(is_free(nextx, nexty, 0, n, m)){
                dist[0][nextx][nexty]=dist[0][currp.first][currp.second]+1;
                which_dir[nextx][nexty]=letters[i];
                parent[nextx][nexty]=currp;
                bfs.push({nextx, nexty});
            }
        }
    }
}

bool can_escape(int x, int y){
    return dist[0][x][y]!=-1 and (dist[1][x][y]==-1 or dist[0][x][y]<dist[1][x][y]);
}
 
string find_path(pair<int, int> startp, pair<int, int> endp){
    pair<int, int> currp=endp;
    string res="";
 
    while(currp!=startp){
        res+=which_dir[currp.first][currp.second];
        currp=parent[currp.first][currp.second];
    }
 
    reverse(res.begin(), res.end());
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,m;
    cin>>n>>m;
 
    pair<int, int> startp;
    vector<pair<int, int>> monsters;
 
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            char curr;
            cin>>curr;
 
            if(curr=='#'){
                for(int type=0;type<2;++type){
                    dist[type][i][i2]=-2;
                }
            }
 
            if(curr=='A'){
                startp={i,i2};
            }
            if(curr=='M'){
                monsters.push_back({i,i2});
            }
        }
    }
 
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            for(int type=0;type<2;++type){
                if(dist[type][i][i2]==0){
                    dist[type][i][i2]=-1;
                }
            }
        }
    }
 
    calc_player(startp, n, m);
    calc_monsters(monsters, n, m);
 
    bool is_res=false;
    string res="";
    
    for(int i=0;i<n and !is_res;++i){
        if(can_escape(i, 0)){
            res=find_path(startp, {i, 0});
            is_res=true;
        }else if(can_escape(i, m-1)){
            res=find_path(startp, {i, m-1});
            is_res=true;
        }
    }
    for(int i=0;i<m and !is_res;++i){
        if(can_escape(0, i)){
            res=find_path(startp, {0, i});
            is_res=true;
        }else if(can_escape(n-1, i)){
            res=find_path(startp, {n-1, i});
            is_res=true;
        }
    }

    if(is_res){
        cout<<"YES\n";
        cout<<(int)res.size()<<endl<<res<<endl;
    }else{
        cout<<"NO\n";
    }
return 0;
}