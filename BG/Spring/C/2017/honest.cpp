#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
vector<pair<int,int>> graph[MAXN];
int component[MAXN],all[MAXN],truth[MAXN];
bool is_honest[MAXN];

void dfs(int currv, int type, int counter){
    component[currv]=counter;
    is_honest[currv]=(type==1);
    for(pair<int,int> nextv : graph[currv]){
        if(!component[nextv.first]){
            dfs(nextv.first,type*nextv.second,counter);
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
        char c;
        cin>>from>>c>>to;
        --from;
        --to;
        int type=(c=='l' ? -1 : 1);
        graph[from].push_back({to,type});
        graph[to].push_back({from,type});
    }

    int counter=1;
    for(int i=0;i<n;++i){
        if(!component[i]){
            dfs(i,1,counter);
            ++counter;
        }
    }
    for(int i=0;i<n;++i){
        ++all[component[i]];
        if(is_honest[i]){
            ++truth[component[i]];
        }
    }

    int res=0;
    for(int i=1;i<counter;++i){
        res+=(2*truth[i]>=all[i] ? truth[i] : all[i]-truth[i]);
    }
    cout<<res<<endl;
return 0;
}