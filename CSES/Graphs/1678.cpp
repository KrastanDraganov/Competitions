#include<iostream>
#include<vector>
#include<algorithm>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=1e5+3;
vector<int> graph[MAXN];
int visited[MAXN],parent[MAXN];
 
bool dfs(int currv, int& cycle_start, int& cycle_end){
    visited[currv]=1;
 
    bool res=false;
    for(int nextv : graph[currv]){
        if(visited[nextv]==1){
            cycle_start=nextv;
            cycle_end=currv;
            visited[currv]=2;
            return true;
        }
 
        if(visited[nextv]==0){
            parent[nextv]=currv;
            res |= dfs(nextv, cycle_start, cycle_end);
        }
    }
    
    visited[currv]=2;
    return res;
}
 
void print_cycle(int startv, int endv){
    vector<int> cycle;
    cycle.push_back(startv);
 
    int currv=endv;
    while(currv!=startv){
        cycle.push_back(currv);
        currv=parent[currv];
    }
    cycle.push_back(startv);
 
    reverse(cycle.begin(), cycle.end());
 
    cout<<(int)cycle.size()<<endl;
    for(int curr : cycle){
        cout<<curr+1<<" ";
    }
    cout<<endl;
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
    }
 
    bool is_cycle=false;
    int cycle_start=-1,cycle_end=-1;
 
    for(int i=0;i<n;++i){
        if(visited[i]==0){
            parent[i]=-1;
            if(dfs(i, cycle_start, cycle_end)){
                is_cycle=true;
                break;
            }
        }
    }
 
    if(!is_cycle){
        cout<<"IMPOSSIBLE\n";
    }else{
        print_cycle(cycle_start, cycle_end);
    }
return 0;
}