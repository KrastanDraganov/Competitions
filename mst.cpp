#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstring>
#include<queue>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
struct Edge {
    int from,to,time;
    Edge(){
        from=0;
        to=0;
        time=0;    
    }
    Edge(int _from, int _to, int _time){
        from=_from;
        to=_to;
        time=_time;
    }
    bool operator<(const Edge& comp) const {
        return time<comp.time;
    }
};
vector<Edge> edges;
vector<pair<int,int>> mst[MAXN];
int parent[MAXN],depth[MAXN],max_edge[MAXN];
bool used[MAXN];
int find_parent(int num){
    if(num==parent[num]){
        return num;
    }
    return parent[num]=find_parent(parent[num]);
} 
void combine(int num1, int num2){
    int root1=find_parent(num1),root2=find_parent(num2);
    if(root1!=root2){
        if(depth[root2]>depth[root1]){
            swap(root1,root2);
        }
        depth[root1]+=depth[root2];
        parent[root2]=root1;
    }
}
void query(int x, int y){
    memset(used,0,sizeof(used));
    memset(max_edge,0,sizeof(max_edge));
    used[x]=true;
    queue<int> bfs;
    bfs.push(x);
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        for(pair<int,int> nextv : mst[curr]){
            if(!max_edge[nextv.first]){
                max_edge[nextv.first]=max(max_edge[nextv.first],nextv.second);
                bfs.push(nextv.first);
                if(nextv.first==y){
                    cout<<max_edge[nextv.first]<<endl;
                    return;
                }
            }
        }
    }
    cout<<"No paths\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        parent[i]=i;
        depth[i]=1;
    }
    for(int i=0;i<m;++i){
        int from,to,time;
        cin>>from>>to>>time;
        edges.push_back(Edge(from,to,time));
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<m;++i){
        if(find_parent(edges[i].from)!=find_parent(edges[i].to)){
            mst[edges[i].from].push_back({edges[i].to,edges[i].time});
            mst[edges[i].to].push_back({edges[i].from,edges[i].time});
            combine(edges[i].from,edges[i].to);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        query(x,y);
    }
    cout<<endl;
return 0;
}