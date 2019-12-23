#include<iostream>
#define endl '\n'
#define MAXN 505
using namespace std;
struct FlightDetails {
    int from,to,fstart;
    FlightDetails(){}
    FlightDetails(int _from, int _to, int _fstart){
        from=_from;
        to=_to;
        fstart=_fstart;
    }
} graph[MAXN];
int vis,onboard[MAXN],fligth[MAXN][MAXN],alltime[MAXN][MAXN],visited[MAXN],used[MAXN];
bool dfs(int x){
    visited[x]=vis;
    for(int i=0;i<x;++i){
        if(fligth[graph[x].from][graph[x].to]+onboard[graph[x].to]+alltime[graph[x].from][graph[i].to]<=graph[i].fstart-graph[x].fstart and (used[i]==-1 or (visited[used[i]]!=vis and dfs(used[i])))){
            used[i]=x;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>onboard[i];
    }
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cin>>fligth[i][i2];
            alltime[i][i2]=fligth[i][i2];
            if(i!=i2){
                alltime[i][i2]+=onboard[i2];
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            for(int i3=0;i3<n;++i3){
                alltime[i2][i3]=min(alltime[i2][i3],alltime[i2][i]+alltime[i][i3]);
            }
        }
    }
    for(int i=0;i<m;++i){
        int from,to,fstart;
        cin>>from>>to>>fstart;
        graph[i]=FlightDetails(from,to,fstart);
    }
    int counter=0;
    for(int i=0;i<m;++i){
        ++vis;
        if(dfs(i)){
            ++counter;
        }
    }
    cout<<m-counter<<endl;
return 0;
}