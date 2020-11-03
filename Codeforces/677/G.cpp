#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,INF=1e9+3;
int dist[MAXN][MAXN],max_cost[MAXN][MAXN];

void calc_shortest_paths(int n){
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            if(dist[i][i2]!=0){
                continue;
            }
            if(i!=i2){
                dist[i][i2]=INF;
            }
        }
    }

    // Floyd-Warshall algorithm
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            for(int i3=0;i3<n;++i3){
                int new_dist=dist[i2][i]+dist[i][i3];
                int curr_cost=max(max_cost[i2][i], max_cost[i][i3]);
                
                if(dist[i2][i3]>new_dist){
                    dist[i2][i3]=new_dist;
                    max_cost[i2][i3]=curr_cost;
                }else if(dist[i2][i3]==new_dist){
                    max_cost[i2][i3]=max(max_cost[i2][i3], curr_cost);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<m;++i){
        int from,to,cost;
        cin>>from>>to>>cost;
        --from;
        --to;

        dist[from][to]=dist[to][from]=cost;
        max_cost[from][to]=max_cost[to][from]=cost;
    }

    calc_shortest_paths(n);

    int res=0,set_to_zero=0;
    for(int i=0;i<k;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;

        res+=dist[from][to];
        set_to_zero=max(set_to_zero, max_cost[from][to]);
    }

    res-=set_to_zero;
    cout<<res<<endl;
return 0;
}