#include<iostream>
#include<vector>
#include<stack>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
vector<int> graph[MAXN],rev_graph[MAXN],res,nz;
stack<int> topological;
bool used[MAXN];
void dfs(int curr){
    used[curr]=true;
    for(int nextv : graph[curr]){
        if(!used[nextv]){
            dfs(nextv);
        }
    }
    topological.push(curr);
}
void rev_dfs(int curr){
    used[curr]=true;
    nz.push_back(curr);
    for(int nextv : rev_graph[curr]){
        if(!used[nextv]){
            rev_dfs(nextv);
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
    stack<int> rev;
    while(!topological.empty()){
        rev.push(topological.top());
        topological.pop();
    }
    while(!rev.empty()){
        nz.clear();
        rev_dfs(rev.top());
        if(nz.size()>res.size()){
            for(int i=0;i<nz.size();++i){
                if(i<res.size()){
                    res[i]=nz[i];
                }else{
                    res.push_back(nz[i]);
                }
            }
        }
        rev.pop();
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(int city : res){
        cout<<city<<" ";
    }
    cout<<<endl;
return 0;
}