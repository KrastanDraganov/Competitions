#include<iostream>
#include<vector>
#include<iomanip>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[2][MAXN];
int timer,in[MAXN],low[MAXN];
bool visited[MAXN];

void find_bridges(int currv, int parent){
    visited[currv]=true;
    in[currv]=low[currv]=timer++;
    for(int nextv : graph[0][currv]){
        if(nextv!=parent){
            if(visited[nextv]){
                low[currv]=min(low[currv],in[nextv]);
            }else{
                find_bridges(nextv,currv);
                low[currv]=min(low[currv],low[nextv]);
                if(low[nextv]<=in[currv]){
                    graph[1][currv].push_back(nextv);
                    graph[1][nextv].push_back(currv);
                }
            }
        }
    }
}

int dfs(int currv){
    visited[currv]=true;
    int res=1;
    for(int nextv : graph[1][currv]){
        if(!visited[nextv]){
            res+=dfs(nextv);
        }
    }
    return res;
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
        graph[0][from].push_back(to);
        graph[0][to].push_back(from);
    }

    find_bridges(0,-1);
    long long res=0;
    for(int i=0;i<n;++i){
        visited[i]=false;
    }
    for(int i=0;i<n;++i){
        if(!visited[i]){
            int counter=dfs(i);
            res+=(long long)counter*(counter-1)/2;
        }
    }
    cout<<res<<endl;
return 0;
}