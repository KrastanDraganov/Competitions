#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int visited[MAXN];
vector<int> graph[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
    }
    
    for(int i=1;i<=n;++i){
        sort(graph[i].rbegin(),graph[i].rend());
    }
    
    stack<int> dfs;
    dfs.push(1);
    visited[1]=true;
    vector<int> res;
    while(!dfs.empty()){
        int curr=dfs.top();
        dfs.pop();
        for(int nextv : graph[curr]){
            if(!visited[nextv]){
                visited[nextv]=true;
                dfs.push(nextv);
            }
        }
        res.push_back(curr);
    }

    for(int curr : res){
        cout<<curr<<" ";
    }
    cout<<endl;
return 0;
}