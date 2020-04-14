#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
vector<int> graph[MAXN];
int timer,in[MAXN],out[MAXN],depth[MAXN],parent[MAXN],wanted[MAXN];

void dfs(int currv, int prev, int currd){
    depth[currv]=currd;
    parent[currv]=prev;
    in[currv]=timer++;
    for(int nextv : graph[currv]){
        if(nextv!=prev){
            dfs(nextv,currv,currd+1);
        }
    }
    out[currv]=timer++;
}

bool on_path(int v1, int v2){
    return in[v2]<=in[v1] and out[v1]<=out[v2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    dfs(0,-1,0);
    
    while(q--){
        int k;
        cin>>k;
        int max_depth=-1;
        for(int i=0;i<k;++i){
            cin>>wanted[i];
            --wanted[i];
            if(i==0 or depth[max_depth]<depth[wanted[i]]){
                max_depth=wanted[i];
            }
            if(parent[wanted[i]]!=-1){
                wanted[i]=parent[wanted[i]];
            }
        }
        bool check=true;
        for(int i=0;i<k;++i){
            if(!on_path(max_depth,wanted[i])){
                check=false;
                break;
            }
        }
        cout<<(check ? "YES" : "NO")<<endl;
    }
return 0;
}