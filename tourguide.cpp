#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
vector<pair<int,int>> graph[MAXN];
int dist[MAXN];
bool in_queue[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }
    int k;
    cin>>k;
    queue<int> spfa;
    for(int i=0;i<MAXN;++i){
        dist[i]=5e8;
    }
    for(int i=0;i<k;++i){
        int special;
        cin>>special;
        spfa.push(special);
        dist[special]=0;
        in_queue[special]=true;
    }
    while(!spfa.empty()){
        int curr=spfa.front();
        in_queue[curr]=false;
        spfa.pop();
        for(pair<int,int> next : graph[curr]){
            if(dist[curr]+next.second<dist[next.first]){
                dist[next.first]=dist[curr]+next.second;
                if(!in_queue[next.first]){
                    spfa.push(next.first);
                    in_queue[next.first]=true;
                }
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int hotel;
        cin>>hotel;
        cout<<dist[hotel]<<endl;
    }
return 0;
}