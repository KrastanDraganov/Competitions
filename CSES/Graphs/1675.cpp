#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MAXM=2e5+3,INF=2e9;

struct Edge {
    int from,to,cost;
    
    Edge(int _from=-1, int _to=-1, int _cost=INF){
        from=_from;
        to=_to;
        cost=_cost;
    }

    bool operator<(const Edge& comp) const {
        return cost<comp.cost;
    }
};

Edge edges[MAXM];
int parent[MAXN],depth[MAXN];

int find_parent(int currv){
    if(currv==parent[currv]){
        return currv;
    }
    return parent[currv]=find_parent(parent[currv]);
}


bool are_combined(int x, int y){
    int root1=find_parent(x),root2=find_parent(y);
    if(root1==root2){
        return true;
    }
    
    if(depth[root1]<depth[root2]){
        swap(root1, root2);
    }
    
    parent[root2]=root1;
    depth[root1]+=depth[root2];
    
    return false;
}

long long find_min_cost(int n, int m){
    // Kruskal Minimum Spanning Tree Algorithm
    sort(edges, edges+m);

    for(int i=0;i<n;++i){
        parent[i]=i;
        depth[i]=1;
    }

    int components=n;
    long long min_cost=0;
    for(int i=0;i<m;++i){
        if(!are_combined(edges[i].from, edges[i].to)){
            --components;
            min_cost+=edges[i].cost;
        }
    }

    return components==1 ? min_cost : -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int from,to,cost;
        cin>>from>>to>>cost;
        edges[i]=Edge(from-1, to-1, cost);
    }

    long long res=find_min_cost(n, m);
    if(res==-1){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<res<<endl;
    }
return 0;
}