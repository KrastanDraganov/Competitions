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
int dist[MAXN][MAXN];

bool is_free(int x, int y, int n, int m){
    return x>=0 and x<n and y>=0 and y<m and dist[x][y]==-1;
}

void calc_bfs(pair<int, int> startp, int n, int m){
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            if(dist[i][i2]==0){
                dist[i][i2]=-1;
            }
        }
    }

    dist[startp.first][startp.second]=0;
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
            
            if(is_free(nextx, nexty, n, m)){
                dist[nextx][nexty]=dist[currp.first][currp.second]+1;
                which_dir[nextx][nexty]=letters[i];
                parent[nextx][nexty]=currp;
                bfs.push({nextx, nexty});
            }
        }
    }
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

    pair<int, int> startp,endp;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            char curr;
            cin>>curr;
            
            if(curr=='#'){
                dist[i][i2]=-2;
            }

            if(curr=='A'){
                startp={i,i2};
            }
            if(curr=='B'){
                endp={i,i2};
            }
        }
    }

    calc_bfs(startp, n, m);

    if(dist[endp.first][endp.second]==-1){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    
    string res=find_path(startp, endp);
    cout<<(int) res.size()<<endl;
    cout<<res<<endl;
return 0;
}