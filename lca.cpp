#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3;
vector<pair<int,int>> graph[MAXN];
int depth[MAXN],lca[MAXN][32];
long long dist[MAXN];

void calc_bfs(){
    queue<int> bfs;
    bfs.push(0);
    memset(depth,-1,sizeof(depth));
    depth[0]=0;
    lca[0][0]=0;
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        for(pair<int,int> nextv : graph[curr]){
            if(depth[nextv.first]==-1){
                depth[nextv.first]=depth[curr]+1;
                dist[nextv.first]=dist[curr]+nextv.second;
                lca[nextv.first][0]=curr;
                bfs.push(nextv.first);
            }
        }
    }
}

void calc_lca(int max_power, int n){
    for(int i=1;i<=n;++i){
        for(int i2=0;i2<n;++i2){
            lca[i2][i]=lca[lca[i2][i-1]][i-1];
        }
    }
}

int find_lca(int x, int y, int max_power){
    if(depth[x]<depth[y]){
        swap(x,y);
    }
    int diff=depth[x]-depth[y];
    for(int i=max_power;diff>0;--i){
        if(diff%2==1){
            x=lca[x][i];
        }
        diff/=2;
    }
    if(x==y){
        return x;
    }
    for(int i=max_power;i>=0;--i){
        if(lca[x][i]!=lca[y][i]){
            x=lca[x][i];
            y=lca[y][i];
        }
    }
    return lca[x][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        --from;
        --to;
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }
    int max_power=0;
    while((1<<max_power)<=n){
        ++max_power;
    }
    --max_power;
    calc_bfs();
    calc_lca(max_power,n);
    while(q--){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        int curr_lca=find_lca(from,to,max_power);
        cout<<dist[from]+dist[to]-2*dist[curr_lca]<<endl;
    }
return 0;
}