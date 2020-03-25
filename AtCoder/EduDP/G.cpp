#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];
int dist[MAXN];
bool visited[MAXN];

void dfs(int curr){
    visited[curr]=true;
    for(int nextp : graph[curr]){
        if(!visited[nextp]){
            dfs(nextp);
        }
        dist[curr]=max(dist[curr],dist[nextp]+1);
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
    }
    for(int i=0;i<n;++i){
        if(!visited[i]){
            dfs(i);
        }
    }
    int res=0;
    for(int i=0;i<n;++i){
        res=max(res,dist[i]);
    }
    cout<<res<<endl;
return 0;
}