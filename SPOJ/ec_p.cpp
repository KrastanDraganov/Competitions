#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=703;
vector<int> graph[MAXN];
vector<pair<int,int>> bridges;
int timer,in[MAXN],min_time[MAXN];
bool visited[MAXN];

void add_bridge(int from, int to){
    if(from>to){
        swap(from,to);
    }
    bridges.push_back({from,to});
}

void dfs(int currv, int parent){
    visited[currv]=true;
    in[currv]=min_time[currv]=timer++;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            if(visited[nextv]){
                min_time[currv]=min(min_time[currv],in[nextv]);
            }else{
                dfs(nextv,currv);
                min_time[currv]=min(min_time[currv],min_time[nextv]);
                if(in[currv]<min_time[nextv]){
                    add_bridge(currv,nextv);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    for(int test=0;test<tests;++test){
        int n,m;
        cin>>n>>m;
        timer=0;
        bridges.clear();
        for(int i=0;i<n;++i){
            graph[i].clear();
            in[i]=1e9;
            min_time[i]=1e9;
            visited[i]=false;
        }
        for(int i=0;i<m;++i){
            int from,to;
            cin>>from>>to;
            --from;
            --to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(i,-1);
            }
        }

        sort(bridges.begin(),bridges.end());
        cout<<"Caso #"<<test+1<<endl;
        if(bridges.empty()){
            cout<<"Sin bloqueos\n";
        }else{
            cout<<(int)bridges.size()<<endl;
            for(pair<int,int> res : bridges){
                cout<<res.first+1<<" "<<res.second+1<<endl;
            }
        }
    }
return 0;
}