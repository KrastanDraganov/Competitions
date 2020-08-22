#include<iostream>
#include<queue>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=2e4+3;
vector<pair<int,int>> graph[MAXN];
int dist[MAXN];
bool in_queue[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int from,to,passengers;
        cin>>from>>to>>passengers;
        graph[from].push_back({to,passengers});
        graph[to].push_back({from,passengers});
    }

    queue<int> spfa;
    spfa.push(0);
    dist[0]=1e9;
    in_queue[0]=true;
    while(!spfa.empty()){
        int curr=spfa.front();
        spfa.pop();
        in_queue[curr]=false;
        for(pair<int,int> nextv : graph[curr]){
            int allowed=min(dist[curr],nextv.second);
            if(allowed>dist[nextv.first]){
                dist[nextv.first]=allowed;
                if(!in_queue[nextv.first]){
                    in_queue[nextv.first]=true;
                    spfa.push(nextv.first);
                }
            }
        }
    }

    for(int i=1;i<n;++i){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
return 0;
}