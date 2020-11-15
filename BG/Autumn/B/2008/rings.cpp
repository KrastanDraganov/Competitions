#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
vector<int> graph[MAXN];

vector<int> calc_bfs(int startv, int n){
    queue<int> bfs;
    bfs.push(startv);

    vector<int> dist(n, -1);
    dist[startv]=0;
    
    while(!bfs.empty()){
        int currv=bfs.front();
        bfs.pop();
        
        for(int nextv : graph[currv]){
            if(dist[nextv]==-1){
                dist[nextv]=dist[currv]+1;
                bfs.push(nextv);
            }
        }
    }

    return dist;
}

int query(int a, int b, int n){
    vector<int> dist_a=calc_bfs(a, n);
    vector<int> dist_b=calc_bfs(b, n);
    
    int res=0;
    for(int i=0;i<n;++i){
        if(dist_a[i]+dist_b[i]!=dist_a[b]){
            ++res;
        }
    }

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
    
    for(int i=0;i<2;++i){
        int x,y;
        cin>>x>>y;
        --x;
        --y;
        cout<<query(x, y, n)<<" ";
    }
    cout<<endl;
return 0;
}