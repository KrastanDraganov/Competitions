#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=603;
vector<int> graph[MAXN];
int in_time[MAXN],min_time[MAXN];

int dfs(int currv, int parent, int& timer){
    in_time[currv]=min_time[currv]=timer++;

    int bridges=0;
    for(int nextv : graph[currv]){
        if(nextv==parent){
            continue;
        }

        if(in_time[nextv]>0){
            min_time[currv]=min(min_time[currv], min_time[nextv]);
            continue;
        }

        bridges+=dfs(nextv, currv, timer);
        min_time[currv]=min(min_time[currv], min_time[nextv]);
        if(min_time[nextv]>in_time[currv]){
            ++bridges;
        }
    }

    return bridges;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int res=0;
    for(int i=0;i<n;++i){
        if(in_time[i]==0){
            int timer=1;
            res+=dfs(i, -1, timer);
        }
    }

    cout<<res<<endl;
return 0;
}
