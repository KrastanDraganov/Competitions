#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,MAXM=1e5+3;
pair<pair<int, int>, int> edges[MAXM];
vector<int> graph[MAXN];
bool used[MAXN];

void dfs(int currv){
    used[currv]=true;
    for(int nextv : graph[currv]){
        if(!used[nextv]){
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
        int from,to,len;
        cin>>from>>to>>len;
        edges[i]={{from-1, to-1}, len};
    }

    int k;
    cin>>k;
    
    for(int i=0;i<m;++i){
        pair<int, int> curr=edges[i].first;
        int len=edges[i].second;
        if(k<=len){
            graph[curr.first].push_back(curr.second);
            graph[curr.second].push_back(curr.first);
        }
    }

    int components=0;
    for(int i=0;i<n;++i){
        if(!used[i]){
            dfs(i);
            ++components;
        }
    }

    cout<<components-1<<endl;
return 0;
}