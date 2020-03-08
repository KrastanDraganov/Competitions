#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int dist[2][MAXN];
vector<int> graph[MAXN];

void calc_bfs(int startv, int ind){
    queue<int> bfs;
    bfs.push(startv);
    dist[ind][startv]=0;
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        for(int nextv : graph[curr]){
            if(dist[ind][nextv]==-1){
                dist[ind][nextv]=dist[ind][curr]+1;
                bfs.push(nextv);
            }
        }
    }
}

int calc_res(int a, int b, int n){
    memset(dist,-1,sizeof(dist));
    calc_bfs(a,0);
    calc_bfs(b,1);
    int ans=0;
    for(int i=0;i<n;++i){
        if(i!=a and i!=b and dist[0][i]+dist[1][i]!=dist[0][b]){
            ++ans;
        }
    }
    return ans;
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
    for(int i=0;i<2;++i){
        int x,y;
        cin>>x>>y;
        --x;
        --y;
        cout<<calc_res(x,y,n)<<" ";
    }
    cout<<endl;
return 0;
}