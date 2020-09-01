//Only 0/100 points

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=3e5+3,MAXM=7e5+3,INF=1e9;
vector<pair<int,int>> graph[MAXN];
int bfs[MAXM],parent[MAXN],depth[MAXN];

int find_parent(int curr){
    if(curr==parent[curr]){
        return curr;
    }
    return parent[curr]=find_parent(parent[curr]);
}

void union_vertex(int num1, int num2){
    int parent1=find_parent(num1),parent2=find_parent(num2);
    if(depth[parent1]!=depth[parent2]){
        if(depth[parent2]>depth[parent1]){
            swap(parent1,parent2);
        }
        depth[parent1]+=depth[parent2];
        parent[parent2]=parent1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;++i){
        parent[i]=i;
        depth[i]=1;
    }
    for(int i=0;i<m;++i){
        int from,to,dtime;
        cin>>from>>to>>dtime;
        --from;
        --to;
        graph[from].push_back({to,dtime});
        graph[to].push_back({from,dtime});
        if(!dtime){
            union_vertex(from,to);
        }
    }
    
    for(int i=0;i<n;++i){
        cout<<i<<" "<<find_parent(i)<<endl;
    }
    
    vector<int> dist(n,-1);
    int bfs_start=0,bfs_end=0;
    priority_queue<int> bfs;
    bfs.push(0);
    dist[find_parent(0)]=0;
    
    while(!bfs.empty()){
        int curr=bfs.top();
        bfs.pop();
        for(pair<int,int> nextv : graph[curr]){
            if(dist[find_parent(nextv.first)]==-1){
                dist[find_parent(nextv.first)]=dist[find_parent(curr)]+1;
                bfs.push(nextv.first);
            }
        }
    }
    
    for(int i=0;i<n;++i){
        int curr=dist[find_parent(i)];
        cout<<(curr==INF ? -1 : curr)<<" ";
    }
    cout<<endl;
return 0;
}