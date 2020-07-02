#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];
bool used[MAXN],is_res[MAXN];
int timer,in[MAXN],min_time[MAXN];

void dfs(int currv, int parent){
    used[currv]=true;
    in[currv]=min_time[currv]=timer++;
    int children=0;
    for(int nextv : graph[currv]){
        if(!used[nextv]){
            ++children;
            dfs(nextv,currv);
            min_time[currv]=min(min_time[currv],min_time[nextv]);
            if(parent!=-1 && min_time[nextv]>=in[currv] && !is_res[currv]){
                is_res[currv]=true;
            }
        }else if(nextv!=parent){
            min_time[currv]=min(min_time[currv],in[nextv]);
        }
    }
    if(parent==-1 and children>1){
        is_res[currv]=true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n=-1,m=-1;
    while(cin>>n>>m){
        if(n==0){
            break;
        }
        timer=0;
        for(int i=0;i<n;++i){
            graph[i].clear();
            used[i]=false;
            is_res[i]=false;
            in[i]=-1;
            min_time[i]=-1;
        }
        for(int i=0;i<m;++i){
            int from,to;
            cin>>from>>to;
            --from;
            --to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        for(int i=0;i<n;++i){
            if(!used[i]){
                dfs(i,-1);
            }
        }
        
        int res=0;
        for(int i=0;i<n;++i){
            res+=is_res[i];
        }
        cout<<res<<endl;
    }
return 0;
}