#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN],rev_graph[MAXN],topological,scc;
bool used[MAXN];

void dfs1(int currv){
    used[currv]=true;
    for(int nextv : graph[currv]){
        if(!used[nextv]){
            dfs1(nextv);
        }
    }
    topological.push_back(currv);
}

void dfs2(int currv){
    used[currv]=true;
    scc.push_back(currv);
    for(int nextv : rev_graph[currv]){
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
    for(int i=0;i<n;++i){
        used[i]=false;
    }
    vector<int> res;
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
    cout<<(int)res.size()<<endl;
    for(int curr : res){
        cout<<curr<<" ";
    }
    cout<<endl;
return 0;
}