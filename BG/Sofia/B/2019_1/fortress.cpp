#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<functional>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
vector<pair<int, int>> graph[MAXN];
int counter[MAXN]; // how many times vertex is used in a shortest path

vector<int> find_shortest_paths(int n, int k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra;
    dijkstra.push({0, 0});

    vector<int> res;
    while(!dijkstra.empty() and counter[n-1]<k){
        pair<int, int> currv;
        while(!dijkstra.empty()){
            pair<int, int> at_top=dijkstra.top();
            dijkstra.pop();
            if(counter[at_top.second]<k){
                currv=at_top;
                break;
            }
        }

        if(currv.second==-1){
            break;
        }

        ++counter[currv.second];
        if(currv.second==n-1){
            res.push_back(currv.first);
        }

        for(pair<int, int> nextv : graph[currv.second]){
            if(counter[nextv.first]<k){
                dijkstra.push({currv.first+nextv.second, nextv.first});
            }
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<m;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        --from;
        --to;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    vector<int> res=find_shortest_paths(n, k);
    for(int curr : res){
        cout<<curr<<" ";
    }
    cout<<endl;
return 0;
}