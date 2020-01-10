#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=1e4+3;
vector<unordered_set<int>> graph;
int parent[MAXN],depth[MAXN];
bool used[MAXN];
int find_parent(int num){
    if(num==parent[num]){
        return num;
    }
    return parent[num]=find_parent(parent[num]);
}
int combine(int num1, int num2){
    int root1=find_parent(num1),root2=find_parent(num2);
    if(root1!=root2){
        if(depth[root2]>depth[root1]){
            swap(root1,root2);
        }
        parent[root2]=root1;
        depth[root1]+=depth[root2];
    }
}
bool check(int x, int y){
    memset(used,0,sizeof(used));
    used[x]=true;
    queue<int> bfs;
    bfs.push(x);
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        for(int nextv : graph[curr]){
            if(nextv==y){
                return true;
            }else if(!used[nextv]){
                used[nextv]=true;
                bfs.push(nextv);
            }
        }
    }
    return false;
}
void calc_bfs(int x){
    memset(used,0,sizeof(used));
    used[x]=true;
    queue<int> bfs;
    bfs.push(x);
    parent[x]=x;
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        for(int nextv : graph[curr]){
            if(!used[nextv]){
                used[nextv]=true;
                parent[nextv]=curr;
                bfs.push(nextv);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n+1;++i){
        depth[i]=1;
        parent[i]=i;
        graph.emplace_back();
    }
    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        graph[from].insert(to);
        graph[to].insert(from);
        combine(from,to);
    }
    int q;
    cin>>q;
    while(q--){
        int type,x,y;
        cin>>type>>x>>y;
        if(type==1){
            cout<<(find_parent(x)==find_parent(y));
        }else if(type==2){
            if(graph[x].find(y)!=graph[x].end()){
                graph[x].erase(y);
                graph[y].erase(x);
                if(!check(x,y)){
                    calc_bfs(x);
                    calc_bfs(y);
                }
            }
        }else{
            graph[x].insert(y);
            graph[y].insert(x);
            combine(x,y);
        }
    }
    cout<<endl;
return 0;
}