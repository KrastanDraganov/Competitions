#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
vector<int> graph[MAXN];
bool used[MAXN],is_res[MAXN];
int timer,res,in[MAXN],min_time[MAXN];
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
                ++res;
                is_res[curr]=true;
            }
        }else if(nextv!=parent){
            min_time[curr]=min(min_time[curr],in[nextv]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n=-1,m=-1;
    while(true){
        cin>>n>>m;
        if(n==0){
            break;
        }
        timer=0;
        res=0;
        for(int i=1;i<=n;++i){
            graph[i].clear();
            used[i]=false;
            is_res[i]=false;
            in[i]=-1;
            min_time[i]=-1;
        }
        for(int i=0;i<m;++i){
            int from,to;
            cin>>from>>to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for(int i=1;i<=n;++i){
            if(!used[i]){
                dfs(i,-1);
            }
        }
        cout<<res<<endl;
    }
return 0;
}