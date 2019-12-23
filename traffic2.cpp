#include<iostream>
#include<vector>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN=5e4+3,MAXM=2e5+3;
vector<int> graph[MAXN],edge_num[MAXN];
pair<int,int> edge[MAXM];
int counter[MAXN];
bool accessible[MAXN],is_closed[MAXM];
void dfs(int curr){
    --counter[curr];
    if(counter[curr]>0 or !accessible[curr]){
        return;
    }
    accessible[curr]=false;
    for(int i=0;i<graph[curr].size();++i){
        if(!is_closed[edge_num[curr][i]]){
            dfs(graph[curr][i]);
            is_closed[edge_num[curr][i]]=true;
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
        edge_num[from].push_back(i);
        ++counter[to];
        edge[i]={from,to};
    }
    for(int i=1;i<=n;++i){
        accessible[i]=true;
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x==2){
            cout<<accessible[y]<<endl;
        }else if(!is_closed[--y]){
            dfs(edge[y].second);
            is_closed[y]=true;
        }
    }
return 0;
}