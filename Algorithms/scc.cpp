#include<iostream>
#include<vector>
#include<stack>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
vector<int> graph[MAXN],rev_graph[MAXN],topo;
bool used[MAXN];

void dfs(int curr){
    used[curr]=true;
    for(int nextv : graph[curr]){
        if(!used[nextv]){
            dfs(nextv);
        }
    }
    topo.push_back(curr);
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

    for(int i=1;i<=n;++i){
        if(!used[i]){
            dfs(i);
        }
    }
    
    for(int i=0;i<MAXN;++i){
        used[i]=false;
    }
    for(int i=(int)topo.size()-1;i>=0;--i){
        if(!used[topo[i]]){
            cout<<"components: ";
            check_dfs(topo[i]);
            cout<<endl;
        }
    }
return 0;
}