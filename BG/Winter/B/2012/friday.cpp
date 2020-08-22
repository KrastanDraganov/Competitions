#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=53,MAXM=5e3,INF=1e8+3;
vector<pair<int,int>> graph[MAXN][13];
int dist[MAXN],dp[MAXN][13][MAXM];

int sol(int node, int remainder, int mask, int endp){
    if(node>=endp) return 0;
    if(dp[node][remainder][mask]!=-1) return dp[node][remainder][mask];
    int ans=INF;
    for(int i=1;i<13;++i){
        if(!(mask & (1<<(i-1)))){
            int ind=(i-remainder+13)%13;
            for(pair<int,int> next : graph[node][ind]){
                ans=min(ans,sol(next.first,i,mask | (1<<(i-1)),endp)+next.second);
            }
        }
    }
    return dp[node][remainder][mask]=ans;
}

int dijkstra(int startp, int endp){
    for(int i=1;i<=endp;++i){
        dist[i]=INF;
    }
    priority_queue<pair<int,int>> pq;
    pq.push({0,startp});
    dist[startp]=0;
    while(!pq.empty()){
        int curr=pq.top().second;
        pq.pop();
        if(curr==endp) return dist[curr];
        for(int i=0;i<13;++i){
            for(pair<int,int> next : graph[curr][i]){
                if(dist[next.first]>dist[curr]+next.second){
                    dist[next.first]=dist[curr]+next.second;
                    pq.push({-dist[next.first],next.first});
                }
            }
        }
    }
    return INF;
}

int check(int res){
    return (res<INF ? res : -1);
}

int calc_res(int n, string& type){
    if(type=="False"){
        return check(dijkstra(1,n));
    }
    for(int i=0;i<MAXN;++i){
        for(int i2=0;i2<13;++i2){
            for(int i3=0;i3<MAXM;++i3){
                dp[i][i2][i3]=-1;
            }
        }
    }
    return check(sol(1,0,0,n));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    for(int test=0;test<t;++test){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<MAXN;++i){
            for(int i2=0;i2<13;++i2){
                graph[i][i2].clear();
            }
        }
        for(int i=0;i<m;++i){
            int from,to,time;
            cin>>from>>to>>time;
            graph[from][time%13].push_back({to,time});
        }
        string type;
        cin>>type;
        cout<<calc_res(n,type)<<endl;
    }
return 0;
}
