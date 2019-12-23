#include<iostream>
#include<cstring>
#include<vector>
#include<utility>
#include<stdio.h>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
vector<pair<int,int>> graph[MAXN];
long long dist[MAXN];
int parent[MAXN],depth[MAXN];
int lca(int node1, int node2){
    if(depth[node1]>depth[node2]){
        do{
            node1=parent[node1];
        }while(depth[node1]>depth[node2]);
    }else if(depth[node2]>depth[node1]){
        do{
            node2=parent[node2];
        }while(depth[node2]>depth[node1]);
    }
    if(node1==node2){
        return node1;
    }
    while(parent[node1]!=parent[node2]){
        node1=parent[node1];
        node2=parent[node2];
    }
    return parent[node1];
}
void dfs(int curr, int head){
    for(pair<int,int> next : graph[curr]){
        if(next.first!=head and !dist[next.first]){
            dist[next.first]=dist[curr]+next.second;
            parent[next.first]=curr;
            depth[next.first]=depth[curr]+1;
            dfs(next.first,head);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("meeting.in","r",stdin);
    freopen("meeting.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i){
        int from,to,price;
        cin>>from>>to>>price;
        graph[from].push_back({to,price});
        graph[to].push_back({from,price});
    }
    dfs(0,0);
    int q;
    cin>>q;
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        long long min_price=1e18;
        int res_node=-1;
        for(int i=0;i<n;++i){
            int lca1=lca(i,a),lca2=lca(i,b),lca3=lca(i,c);
            long long curr=3*dist[i]+dist[a]+dist[b]+dist[c]-2*dist[lca1]-2*dist[lca2]-2*dist[lca3];
            if(curr<min_price){
                min_price=curr;
                res_node=i;
            }
        }
        cout<<res_node<<" "<<min_price<<endl;
    }
return 0;
}
