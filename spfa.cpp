#include<iostream>
#include<vector>
#include<utility>
#include<math.h>
#define endl '\n'
#define MAXN 20001
using namespace std;
const int INF=1e9;
int dist[MAXN],spfa[4*MAXN],qstart,qend;
bool inqueue[MAXN];
vector<pair<int,int>> graph[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,p,t;
        cin>>a>>b>>p>>t;
        graph[a].push_back({b,fabs(p-t)});
        graph[b].push_back({a,fabs(p-t)});
    }
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    dist[1]=0;
    spfa[qend++]=1;
    while(qend-qstart>0){
        int curr=spfa[qstart++];
        inqueue[curr]=false;
        for(pair<int,int> next : graph[curr]){
            if(dist[next.first]>dist[curr]+next.second){
                dist[next.first]=dist[curr]+next.second;
                if(!inqueue[next.first]){
                    inqueue[next.first]=true;
                    spfa[qend++]=next.first;
                }
            }
        }
    }
    cout<<k-dist[n]<<endl;
return 0;
}
