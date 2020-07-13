#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=70,MAXD=1e4+3;
vector<pair<int,int>> graph[MAXN];
vector<vector<int>> paths[MAXD];
vector<int> curr_path;
bool visited[MAXN];

void dfs(int currv, int dist, int endp, int max_dist){
    curr_path.push_back(currv);
    if(currv==endp and dist<=max_dist){
        paths[dist].push_back(curr_path);
        curr_path.pop_back();
        return;
    }
    visited[currv]=true;
    for(pair<int,int> nextv : graph[currv]){
        if(!visited[nextv.first]){
            dfs(nextv.first,dist+nextv.second,endp,max_dist);
        }
    }
    visited[currv]=false;
    curr_path.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int from,to,dist;
        cin>>from>>to>>dist;
        --from;
        --to;
        graph[from].push_back({to,dist});
        graph[to].push_back({from,dist});
    }
    int startp,endp,max_dist;
    cin>>startp>>endp>>max_dist;
    --startp;
    --endp;

    dfs(startp,0,endp,max_dist);
    bool is_path=false;
    for(int i=0;i<=max_dist;++i){
        if(!paths[i].empty()){
            sort(paths[i].begin(),paths[i].end());
            for(vector<int> res : paths[i]){
                cout<<i<<": ";
                for(int currv : res){
                    cout<<currv+1<<" ";
                }
                cout<<endl;
            }
            is_path=true;
        }
    }
    if(!is_path){
        cout<<"There are no suitable routes\n";
    }
return 0;
}