#include<iostream>
#include<vector>
#include<utility>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN],levels[MAXN];
int res[MAXN],depth[MAXN],parent[MAXN];
bool visited[MAXN];
pair<int,int> edge[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        edge[i]={from,to};
        graph[from].push_back(to);
        graph[to].push_back(from);
        depth[i]=-1;
    }
    depth[n-1]=-1;
    depth[n]=-1;
    queue<int> bfs;
    bfs.push(0);
    depth[0]=0;
    parent[0]=-1;
    int max_depth=0;
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        for(int nextv : graph[curr]){
            if(depth[nextv]==-1){
                depth[nextv]=depth[curr]+1;
                max_depth=max(max_depth,depth[nextv]);
                levels[depth[nextv]].push_back(nextv);
                parent[nextv]=curr;
                bfs.push(nextv);
            }
        }
    }
    int lower=0,bigger=n-2;
    for(int i=max_depth;i>0;--i){
        for(int curr : levels[i]){
            if(!visited[curr]){
                res[curr]=lower++;
                visited[curr]=true;
                curr=parent[curr];
                while(curr!=0 and !visited[curr]){
                    res[curr]=bigger--;
                    visited[curr]=true;
                    curr=parent[curr];
                }
            }
        }
    }
    for(int i=0;i<n-1;++i){
        int v1=edge[i].first,v2=edge[i].second;
        if(depth[v1]<depth[v2]){
            swap(v1,v2);
        }
        cout<<res[v1]<<endl;
    }
return 0;
}