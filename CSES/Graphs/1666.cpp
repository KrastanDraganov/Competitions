#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
bool visited[MAXN];
vector<int> graph[MAXN];

void dfs(int currv){
    visited[currv]=true;
    
    for(int nextv : graph[currv]){
        if(!visited[nextv]){
            dfs(nextv);
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
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> components;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            components.push_back(i+1);
            dfs(i);
        }
    }

    int res_size=(int) components.size()-1;
    cout<<res_size<<endl;
    for(int i=0;i<res_size;++i){
        cout<<components[i]<<" "<<components[i+1]<<endl;
    }
return 0;
}