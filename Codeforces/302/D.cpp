#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=3e3+3,INF=1e9;
vector<int> graph[MAXN];
int dist[MAXN][MAXN];

void calc_dist(int startp){
    queue<int> bfs;
    bfs.push(startp);
    dist[startp][startp]=0;
    while(!bfs.empty()){
        int currv=bfs.front();
        bfs.pop();
        for(int nextv : graph[currv]){
            if(dist[startp][nextv]==INF){
                dist[startp][nextv]=dist[startp][currv]+1;
                bfs.push(nextv);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int s1,t1,l1,s2,t2,l2;
    cin>>s1>>t1>>l1>>s2>>t2>>l2;
    --s1;
    --t1;
    --s2;
    --t2;

    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            dist[i][i2]=INF;
        }
        calc_dist(i);
    }

    int needed=INF;
    if(dist[s1][t1]<=l1 and dist[s2][t2]<=l2){
        needed=dist[s1][t1]+dist[s2][t2];
    }
    for(int i=0;i<2;++i){
        swap(s1,t1);
        for(int x=0;x<n;++x){
            for(int y=0;y<n;++y){
                int d1=dist[s1][x]+dist[x][y]+dist[y][t1];
                int d2=dist[s2][x]+dist[x][y]+dist[y][t2];
                if(d1<=l1 and d2<=l2){
                    needed=min(needed,d1+d2-dist[x][y]);
                }
            }
        }
    }
    cout<<(needed>m ? -1 : m-needed)<<endl;
return 0;
}