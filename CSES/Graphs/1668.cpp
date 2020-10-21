#include<iostream>
#include<vector>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=1e5+3;
vector<int> graph[MAXN];
int color[MAXN];
 
bool dfs(int currv, int prev){
    bool res=true;
    for(int nextv : graph[currv]){
        if(nextv==prev){
            continue;
        }
        if(color[nextv]==color[currv]){
            return false;
        }
        if(color[nextv]==0){
            color[nextv]=(color[currv]==1 ? 2 : 1);
            res &= dfs(nextv, currv);
        }
    }
    return res;
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
 
    bool is_possible=true;
    for(int i=0;i<n;++i){
        if(color[i]==0){
            color[i]=1;
            is_possible &= dfs(i, -1);
        }
    }
 
    if(!is_possible){
        cout<<"IMPOSSIBLE\n";
    }else{
        for(int i=0;i<n;++i){
            cout<<color[i]<<" ";
        }
        cout<<endl;
    }
return 0;
}