#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=503;
const long long INF=(long long)(1e18);
long long dist[MAXN][MAXN];

void find_shortest_paths(int n){
    // Floyd-Warshall algorithm
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            for(int i3=0;i3<n;++i3){
                dist[i2][i3]=min(dist[i2][i3], dist[i2][i]+dist[i][i3]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,q;
    cin>>n>>m>>q;

    for(int i=0;i<n;++i){
        for(int i2=i+1;i2<n;++i2){
            dist[i][i2]=dist[i2][i]=INF;
        }
    }

    for(int i=0;i<m;++i){
        int from,to;
        long long weight;
        cin>>from>>to>>weight;
        --from;
        --to;
        dist[from][to]=dist[to][from]=min(dist[from][to], weight);
    }

    find_shortest_paths(n);

    while(q--){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        cout<<(dist[from][to]==INF ? -1 : dist[from][to])<<endl;
    }
return 0;
}