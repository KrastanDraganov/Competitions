#include<iostream>
#include<vector>
#include<utility>
#include<math.h>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=2e4+3,INF=1e9;
int dist[MAXN],spfa[4*MAXN];
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
    queue<int> spfa;
    spfa.push(1);

    while(!spfa.empty()){
        int curr=spfa.front();
        spfa.pop();
        inqueue[curr]=false;

        for(pair<int,int> nextv : graph[curr]){
            if(dist[nextv.first]>dist[curr]+nextv.second){
                dist[nextv.first]=dist[curr]+nextv.second;
                if(!inqueue[nextv.first]){
                    inqueue[nextv.first]=true;
                    spfa.push(nextv.first);
                }
            }
        }
    }
    cout<<k-dist[n]<<endl;
return 0;
}
