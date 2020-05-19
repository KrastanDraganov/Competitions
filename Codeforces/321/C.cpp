#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];
bool is_cat[MAXN];

int dfs(int currv, int parent, int cats, int m){
    if(is_cat[currv]){
        cats+=is_cat[currv];
        if(cats>m){
            return 0;
        }
    }else{
        cats=0;
    }
    int res=0;
    bool is_leaf=true;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            res+=dfs(nextv,currv,cats,m);
            is_leaf=false;
        }
    }
    return (is_leaf ? 1 : res);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>is_cat[i];
    }
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    cout<<dfs(0,-1,0,m)<<endl;
return 0;
}