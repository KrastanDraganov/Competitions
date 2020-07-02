#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=103;
bool graph[MAXN][MAXN],rev_graph[MAXN][MAXN];
vector<int> topological;
bool used[MAXN];

void dfs1(int currv, int n){
    used[currv]=true;
    for(int nextv=0;nextv<n;++nextv){
        if(graph[currv][nextv] and !used[nextv]){
            dfs1(nextv,n);
        }
    }
    topological.push_back(currv);
}

void dfs2(int currv, int n){
    used[currv]=true;
    for(int nextv=0;nextv<n;++nextv){
        if(rev_graph[currv][nextv] and !used[nextv]){
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
        for(int i=0;i<n;++i){
            for(int i2=0;i2<n;++i2){
                graph[i][i2]=false;
                rev_graph[i][i2]=false;
            }
        }
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
        
        for(int i=0;i<n;++i){
            used[i]=false;
        }
        for(int i=0;i<n;++i){
            if(!used[i]){
                dfs1(i,n);
            }
        }
        
        for(int i=0;i<n;++i){
            used[i]=false;
        }
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