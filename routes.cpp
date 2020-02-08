#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN=3e5+3,MAXM=7e5+3,INF=1e9;
vector<pair<int,int>> graph[MAXN];
int bfs[MAXM];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int from,to,dtime;
        cin>>from>>to>>dtime;
        --from;
        --to;
        graph[from].push_back({to,dtime});
        graph[to].push_back({from,dtime});
    }
    vector<int> dist(n,INF);
    int bfs_start=0,bfs_end=0;
    bfs[bfs_end++]=0;
    dist[0]=0;
    while(bfs_end-bfs_start>0){
        int curr=bfs[bfs_start++];
        for(pair<int,int> nextv : graph[curr]){
            int curr_dist=dist[curr]+nextv.second;
            if(dist[nextv.first]>curr_dist){
                dist[nextv.first]=curr_dist;
                bfs[bfs_end++]=nextv.first;
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<(dist[i]==INF ? -1 : dist[i])<<" ";
    }
    cout<<endl;
return 0;
}