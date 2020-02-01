#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=103;
bool graph[MAXN][MAXN],rev_graph[MAXN][MAXN];
vector<int> topological;
bool used[MAXN];
void dfs1(int curr, int n){
    used[curr]=true;
    for(int nextv=0;nextv<n;++nextv){
        if(graph[curr][nextv] and !used[nextv]){
            dfs1(nextv,n);
        }
    }
    topological.push_back(curr);
}
void dfs2(int curr, int n){
    used[curr]=true;
    for(int nextv=0;nextv<n;++nextv){
        if(rev_graph[curr][nextv] and !used[nextv]){
            dfs2(nextv,n);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        memset(graph,0,sizeof(graph));
        memset(rev_graph,0,sizeof(rev_graph));
        topological.clear();
        for(int i=0;i<n;++i){
            for(int i2=0;i2<n;++i2){
                char curr;
                cin>>curr;
                bool is_friend=(curr=='Y');
                graph[i][i2]=is_friend;
                rev_graph[i2][i]=is_friend;
            }
        }
        memset(used,0,sizeof(used));
        for(int i=0;i<n;++i){
            if(!used[i]){
                dfs1(i,n);
            }
        }
        memset(used,0,sizeof(used));
        int res=0;
        for(int i=n-1;i>=0;--i){
            if(!used[topological[i]]){
                dfs2(topological[i],n);
                ++res;
            }
        }
        cout<<res<<endl;
    }
return 0;
}