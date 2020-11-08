#include<iostream>
#include<vector>
#include<queue>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=1e5+3;
const long long INF=(long long)(1e18);
vector<pair<int, int>> graph[MAXN];
int counter[MAXN];
long long dist[MAXN];
bool in_queue[MAXN],visited[MAXN];

void dfs(int currv){
    visited[currv]=true;
    for(pair<int, int> nextv : graph[currv]){
        if(!visited[nextv.first]){
            dfs(nextv.first);
        }
    }
}
 
bool find_max_score(int n){
    for(int i=0;i<n;++i){
        dist[i]=-INF;
    }
 
    queue<int> spfa;
    spfa.push(0);
    dist[0]=0;
    in_queue[0]=true;
 
    while(!spfa.empty()){
        int currv=spfa.front();
        spfa.pop();
        in_queue[currv]=false;
 
        for(pair<int, int> nextv : graph[currv]){
            long long new_dist=dist[currv]+nextv.second;
            
            if(new_dist<=dist[nextv.first]){
                continue;
            }
            dist[nextv.first]=new_dist;
            
            if(in_queue[nextv.first]){
                continue;
            }
            in_queue[nextv.first]=true;

            ++counter[nextv.first];
            if(counter[nextv.first]>n){
                continue;
            }

            spfa.push(nextv.first);
        }
    }

    for(int i=0;i<n;++i){
        if(counter[i]>n){
            dfs(i);
        }
    }
 
    return !visited[n-1];
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,m;
    cin>>n>>m;
 
    for(int i=0;i<m;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        --from;
        --to;
        graph[from].push_back({to, weight});
    }
 
    cout<<(find_max_score(n) ? dist[n-1] : -1)<<endl;
return 0;
}