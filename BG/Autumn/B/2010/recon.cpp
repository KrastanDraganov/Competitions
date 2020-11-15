#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

struct Edge {
    int from,to,dist;
    
    Edge(int _from=-1, int _to=-1, int _dist=0){
        from=_from;
        to=_to;
        dist=_dist;
    }

    bool operator<(const Edge& comp) {
        return dist<comp.dist;
    }
};

const int MAXN=(1<<10)+3;
vector<int> graph[MAXN];
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<Edge> edges;
    for(int from=0;from<n-1;++from){
        for(int to=from+1;to<n;++to){
            int dist;
            cin>>dist;
            edges.push_back(Edge(from, to, dist));
        }
    }

    for(int i=0;i<n;++i){
        parent[i]=i;
        depth[i]=1;
    }

    sort(edges.begin(), edges.end());
    for(Edge curr : edges){
        if(!are_combined(curr.from, curr.to)){
            graph[curr.from].push_back(curr.to);
            graph[curr.to].push_back(curr.from);
        }
    }

    for(int i=0;i<n;++i){
        sort(graph[i].begin(), graph[i].end());
        cout<<(int)graph[i].size()<<" ";
        for(int currv : graph[i]){
            cout<<currv+1<<" ";
        }
        cout<<endl;
    }
return 0;
}