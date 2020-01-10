#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=2e5+3;
struct Edge {
    int from,to,ind;
    long long effort,profit;
    Edge(){
        from=0;
        to=0;
        effort=0;
        profit=0;
        ind=-1;   
    }
    Edge(int _from, int _to, long long _effort, long long _profit, int _ind){
        from=_from;
        to=_to;
        effort=_effort;
        profit=_profit;
        ind=_ind;
    }
    bool operator<(const Edge& comp) const {
        return (effort<comp.effort or (effort==comp.effort and profit>comp.profit));
    }
};
vector<Edge> edges;
int parent[MAXN],depth[MAXN];
int find_parent(int num){
    if(num==parent[num]){
        return num;
    }
    return parent[num]=find_parent(parent[num]);
} 
void combine(int num1, int num2){
    int root1=find_parent(num1),root2=find_parent(num2);
    if(root1!=root2){
        if(depth[root2]>depth[root1]){
            swap(root1,root2);
        }
        depth[root1]+=depth[root2];
        parent[root2]=root1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        parent[i]=i;
        depth[i]=1;
    }
    for(int i=0;i<m;++i){
        int from,to;
        long long effort,profit;
        cin>>from>>to>>effort>>profit;
        edges.push_back(Edge(from,to,effort,profit,i+1));
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<m;++i){
        if(find_parent(edges[i].from)!=find_parent(edges[i].to)){
            combine(edges[i].from,edges[i].to);
            cout<<edges[i].ind<<endl;
        }
    }
return 0;
}