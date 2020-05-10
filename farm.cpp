#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=5e4+3;
vector<int> graph[MAXN],leaves;
int timer,in[MAXN],out[MAXN],dist[MAXN];

void dfs(int currv, int parent){
    if(parent!=-1){
        dist[currv]=dist[parent]+1;
    }
    in[currv]=timer++;
    bool is_leaf=true;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            is_leaf=false;
            dfs(nextv,currv);
        }
    }
    out[currv]=timer++;
    if(is_leaf){
        leaves.push_back(currv);
    }
}

bool cmp(int node1, int node2){
    return dist[node1]>dist[node2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    dfs(0,-1);
    sort(leaves.begin(),leaves.end(),cmp);
    int min_dist=1e9,pos=-1;
    for(int i=0;i<n;++i){
        int curr=0;
        if(in[i]<=in[leaves[0]] and out[leaves[0]]<=out[i]){
            curr=max(curr,dist[leaves[0]]-dist[i]);
            curr=max(curr,dist[i]+dist[leaves[1]]);
        }else{
            curr=max(curr,dist[i]+dist[leaves[0]]);
        }
        if(curr<min_dist){
            min_dist=curr;
            pos=i+1;
        }
    }
    cout<<min_dist<<endl<<pos<<endl;
return 0;
}