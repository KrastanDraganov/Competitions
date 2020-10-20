#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];
int dist[MAXN],parent[MAXN];

void calc_bfs(int n){
    for(int i=0;i<n;++i){
        dist[i]=-1;
    }

    queue<int> bfs;
    bfs.push(0);
    dist[0]=0;
    parent[0]=-1;

    while(!bfs.empty()){
        int currv=bfs.front();
        bfs.pop();

        for(int nextv : graph[currv]){
            if(dist[nextv]==-1){
                dist[nextv]=dist[currv]+1;
                parent[nextv]=currv;
                bfs.push(nextv);
            }
        }
    }
}

vector<int> find_path(int n){
    vector<int> res;
    int currv=n-1;
    
    while(currv!=-1){
        res.push_back(currv);
        currv=parent[currv];
    }

    reverse(res.begin(), res.end());
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    calc_bfs(n);

    if(dist[n-1]==-1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    vector res=find_path(n);
    cout<<(int) res.size()<<endl;
    for(int curr : res){
        cout<<curr+1<<" ";
    }
    cout<<endl;
return 0;
}