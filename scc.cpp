#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=1e3+3;
vector<int> graph[MAXN],rev_graph[MAXN];
bool used[MAXN];
stack<int> topological;
void dfs(int curr){
    used[curr]=true;
    for(int nextv : graph[curr]){
        if(!used[nextv]){
            dfs(nextv);
        }
    }
    topological.push(curr);
}
void check_dfs(int curr){
    used[curr]=true;
    cout<<curr<<" ";
    for(int nextv : rev_graph[curr]){
        if(!used[nextv]){
            check_dfs(nextv);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        rev_graph[to].push_back(from);
    }
    int num=1;
    for(int i=1;i<=n;++i){
        if(!used[i]){
            dfs(i);
        }
    }
    stack<int> rev;
    memset(used,0,sizeof(used));
    while(!topological.empty()){
        rev.push(topological.top());
        topological.pop();
    }
    while(!rev.empty()){
        if(!used[rev.top()]){
            cout<<"components: ";
            check_dfs(rev.top());
            cout<<endl;
        }
        rev.pop();
    }
return 0;
}