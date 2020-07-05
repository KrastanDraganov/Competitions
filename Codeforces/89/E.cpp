#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<pair<int,int>> graph[MAXN];
pair<int,int> edges[3*MAXN];
int timer,in[MAXN],low[MAXN];
bool visited[MAXN],used_edge[3*MAXN];

void dfs(int currv, bool& is_bridge){
    in[currv]=low[currv]=timer++;
    visited[currv]=true;
    for(pair<int,int> edge : graph[currv]){
        int nextv=edge.first,ind=edge.second;
        if(!used_edge[ind]){
            used_edge[ind]=true;
            if(currv!=edges[ind].first){
                swap(edges[ind].first,edges[ind].second);
            }
            if(visited[nextv]){
                low[currv]=min(low[currv],low[nextv]);
            }else{
                dfs(nextv,is_bridge);
                low[currv]=min(low[currv],low[nextv]);
                if(low[nextv]>in[currv]){
                    is_bridge=true;
                }
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
        edges[i]={from,to};
        graph[from].push_back({to,i});
        graph[to].push_back({from,i});
    }

    bool is_bridge=false;
    dfs(0,is_bridge);
    if(is_bridge){
        cout<<"0\n";
    }else{
        for(int i=0;i<m;++i){
            cout<<edges[i].first+1<<" "<<edges[i].second+1<<endl;
        }
    }
return 0;
}