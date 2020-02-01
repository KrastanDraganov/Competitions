#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
vector<int> graph[MAXN],rev_graph[MAXN],topological,res,scc;
bool used[MAXN];
void dfs1(int curr){
    used[curr]=true;
    for(int nextv : graph[curr]){
        if(!used[nextv]){
            dfs1(nextv);
        }
    }
    topological.push_back(curr);
}
void dfs2(int curr){
    used[curr]=true;
    scc.push_back(curr);
    for(int nextv : rev_graph[curr]){
        if(!used[nextv]){
            dfs2(nextv);
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
            dfs1(i);
        }
    }
    memset(used,0,sizeof(used));
    for(int i=n-1;i>=0;--i){
        if(!used[topological[i]]){
            dfs2(topological[i]);
            if(scc.size()>1){
                for(int curr : scc){
                    res.push_back(curr);
                }
            }
            scc.clear();
        }
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(int curr : res){
        cout<<curr<<" ";
    }
    cout<<endl;
return 0;
}