#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=2e5+3;
vector<int> graph[MAXN];
int parent[MAXN],dist[MAXN];
pair<int,int> dfs(int curr, int curr_dist){
    pair<int,int> res={curr_dist,curr};
    for(int nextv : graph[curr]){
        if(nextv!=parent[curr]){
            parent[nextv]=curr;
            res=max(res,dfs(nextv,curr_dist+1));
        }
    }
    return res;
}
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
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    parent[0]=-1;
    pair<int,int> firstv=dfs(0,0);
    parent[firstv.second]=-1;
    pair<int,int> secondv=dfs(firstv.second,0);
    int currv=secondv.second;
    vector<int> diameter;
    while(currv!=firstv.second){
        diameter.push_back(currv);
        currv=parent[currv];
    }
    diameter.push_back(firstv.second);
    if((int)diameter.size()==n){
        cout<<n-1<<endl<<firstv.second+1<<" "<<secondv.second+1<<" "<<diameter[1]+1<<endl;
    }else{
        queue<int> bfs;
        memset(dist,-1,sizeof(dist));
        for(int curr : diameter){
            bfs.push(curr);
            dist[curr]=0;
        }
        while(!bfs.empty()){
            int curr=bfs.front();
            bfs.pop();
            for(int nextv : graph[curr]){
                if(dist[nextv]==-1){
                    dist[nextv]=dist[curr]+1;
                    bfs.push(nextv);
                }
            }
        }
        pair<int,int> res={-1,-1};
        for(int i=0;i<n;++i){
            res=max(res,{dist[i],i});
        }
        cout<<(int)diameter.size()+res.first-1<<endl<<firstv.second+1<<" "<<secondv.second+1<<" "<<res.second+1<<endl;
    }
return 0;
}