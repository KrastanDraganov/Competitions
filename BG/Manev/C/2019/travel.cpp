#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int ans[MAXN],parent[MAXN],nextv[MAXN];
vector<int> graph[MAXN];
vector<pair<int,int>> request[MAXN];
bool used[MAXN];

void dfs(int x){    
    for(pair<int,int> curr : request[x]){
        if(nextv[curr.first]==0){
            ans[curr.second]=-curr.first;
        }else{
            ans[curr.second]=nextv[curr.first];
        }
    }
    
    for(int curr : graph[x]){
        if(curr!=parent[x]){
            parent[curr]=x;
            nextv[x]=curr;
            dfs(curr);
        }
    }
    nextv[x]=parent[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        request[v].push_back({u,i});
    }
    
    dfs(1);
    
    for(int i=0;i<m;i++){
        if(ans[i]>=0){
            cout<<ans[i]<<endl;
        }else{
            cout<<parent[-ans[i]]<<endl;
        }
    }
return 0;
}