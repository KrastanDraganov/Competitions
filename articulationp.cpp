#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN=1e4+3;
vector<int> graph[MAXN],res;
bool used[MAXN],is_res[MAXN];
int timer,in[MAXN],min_time[MAXN];
bool is_tree;
void dfs(int curr, int parent){
    used[curr]=true;
    int children=0;
    in[curr]=min_time[curr]=timer++;
    for(int nextv : graph[curr]){
        if(!used[nextv]){
            ++children;
            dfs(nextv,curr);
            min_time[curr]=min(min_time[curr],min_time[nextv]);
            if(parent>-1 && min_time[nextv]>=in[curr] && !is_res[curr]){
                res.push_back(curr);
                is_res[curr]=true;
            }
        }else if(nextv!=parent){
            min_time[curr]=min(min_time[curr],in[nextv]);
        }
    }
    if(parent==-1 and children>1 and !is_res[curr]){
        res.push_back(curr);
        is_res[curr]=true;
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
        graph[to].push_back(from);
    }
    for(int i=0;i<n;++i){
        if(!used[i]){
            dfs(i,-1);
        }
    }
    for(int point : res){
        cout<<point<<endl;
    }
return 0;
}