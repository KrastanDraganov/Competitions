#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

struct Edge {
    int from,to,weight;
    Edge(int _from=-1, int _to=-1, int _weight=0){
        from=_from;
        to=_to;
        weight=_weight;
    }
};

const int MAXN=2503,MAXM=5e3+3;
const long long INF=(long long)(1e18);

Edge edges[MAXM];
int parent[MAXN];
long long dist[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        edges[i]=Edge(from-1, to-1, weight);
    }

    for(int i=0;i<n;++i){
        dist[i]=INF;
        parent[i]=-1;
    }
    dist[0]=0;

    // Bellman-Ford algorithm
    int last_relaxed=-2;
    for(int i=0;i<n and last_relaxed!=-1;++i){
        last_relaxed=-1;
        for(int i=0;i<m;++i){
            long long new_dist=dist[edges[i].from]+edges[i].weight;
            if(dist[edges[i].to]>new_dist){
                dist[edges[i].to]=max(-INF, new_dist);
                parent[edges[i].to]=edges[i].from;
                last_relaxed=edges[i].to;
            }
        }
    }

    if(last_relaxed==-1){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        
        int cycle_start=last_relaxed;
        for(int i=0;i<n;++i){
            cycle_start=parent[cycle_start];
        }

        vector<int> cycle;
        int currv=cycle_start;
        do{
            cycle.push_back(currv);
            currv=parent[currv];
        } while(currv!=cycle_start);
        cycle.push_back(cycle_start);

        reverse(cycle.begin(), cycle.end());
        for(int currv : cycle){
            cout<<currv+1<<" ";
        }
        cout<<endl;
    }
return 0;
}