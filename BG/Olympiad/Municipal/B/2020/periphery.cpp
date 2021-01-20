#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];

vector<int> find_periphery(int startv, int k, int n){
    queue<int> bfs;
    bfs.push(startv);
    
    vector<int> dist(n, -1);
    dist[startv]=0;

    vector<int> kperiphery;
    while(!bfs.empty()){
        int currv=bfs.front();
        bfs.pop();

        if(dist[currv]>k){
            kperiphery.push_back(currv);
        }

        for(int nextv : graph[currv]){
            if(dist[nextv]==-1){
                dist[nextv]=dist[currv]+1;
                bfs.push(nextv);
            }
        }
    }

    sort(kperiphery.begin(), kperiphery.end());
    return kperiphery;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n,m,c,k;
    cin>>n>>m>>c>>k;
    --c;

    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> res=find_periphery(c, k, n);
    
    cout<<(int)res.size()<<endl;
    for(int currv : res){
        cout<<currv+1<<endl;
    }
return 0;
}