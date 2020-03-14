#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
vector<int> graph[MAXN];
int color[MAXN],dp[MAXN],res[MAXN];

void dfs1(int curr, int parent){
    dp[curr]=color[curr];
    for(int nextv : graph[curr]){
        if(nextv!=parent){
            dfs1(nextv,curr);
            dp[curr]=max(dp[curr],dp[curr]+dp[nextv]);
        }
    }
}

void dfs2(int curr, int parent, int weight){
    res[curr]=dp[curr]+weight;
    for(int nextv : graph[curr]){
        if(nextv!=parent){
            dfs2(nextv,curr,max(0,res[curr]-max(dp[nextv],0)));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>color[i];
        if(color[i]==0){
            color[i]=-1;
        }
    }
    for(int i=0;i<n-1;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    dfs1(0,-1);
    dfs2(0,-1,0);
    for(int i=0;i<n;++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
return 0;
}