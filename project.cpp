#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<pair<int,int>> graph[2][MAXN];
vector<int> topo;
pair<pair<int,int>,int> edges[2*MAXN];
int in_degree[MAXN],min_time[MAXN],max_time[MAXN];

void dfs(int currv){
    --in_degree[currv];
    if(in_degree[currv]>0){
        return;
    }
    topo.push_back(currv);
    for(pair<int,int> nextv : graph[0][currv]){
        min_time[nextv.first]=max(min_time[nextv.first],min_time[currv]+nextv.second);
        if(in_degree[nextv.first]){
            dfs(nextv.first);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        ++in_degree[to];
        graph[0][from].push_back({to,weight});
        graph[1][to].push_back({from,weight});
        edges[i]={{from,to},weight};
    }

    for(int i=0;i<n;++i){
        if(!in_degree[i]){
            dfs(i);
        }
    }
    int res=0;
    for(int i=0;i<n;++i){
        res=max(res,min_time[i]);
    }
    
    for(int i=0;i<n;++i){
        max_time[i]=res;
    }
    for(int i=n-1;i>=0;--i){
        for(pair<int,int> nextv : graph[1][topo[i]]){
            max_time[nextv.first]=min(max_time[nextv.first],max_time[topo[i]]-nextv.second);
        }
    }

    cout<<res<<endl;
    for(int i=0;i<m;++i){
        pair<int,int> curr=edges[i].first;
        cout<<min_time[curr.first]<<" "<<max_time[curr.second]-edges[i].second<<endl;
    }
return 0;
}
