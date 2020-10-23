#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[2][2*MAXN];
bool visited[2*MAXN],res[MAXN];
int component[2*MAXN];

void modify_val(int& num){
    if(num<0){
        num=2*(-num)+1;
    }else{
        num=2*num;
    }
}

int opposite(int num){
    if(num & 1){
        return num-1;
    }
    return num+1;
}

void dfs(int currv, vector<int>& topo){
    visited[currv]=true;
    for(int nextv : graph[0][currv]){
        if(!visited[nextv]){
            dfs(nextv, topo);
        }
    }
    topo.push_back(currv);
}

void dfs2(int currv, int id){
    component[currv]=id;
    for(int nextv : graph[1][currv]){
        if(component[nextv]==-1){
            dfs2(nextv, id);
        }
    }
}

bool is_sol(int n){
    vector<int> topo;
    for(int i=2;i<n;++i){
        if(!visited[i]){
            dfs(i, topo);
        }
    }

    for(int i=2;i<n;++i){
        component[i]=-1;
    }

    int counter=0;
    for(int i=n-3;i>=0;--i){
        if(component[topo[i]]==-1){
            dfs2(topo[i], counter++);
        }
    }

    for(int i=2;i<n;i+=2){
        if(component[i]==component[i+1]){
            return false;
        }
        res[i/2]=(component[i+1]<component[i]);
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    n=2*n+2;

    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        
        modify_val(from);
        modify_val(to);

        graph[0][opposite(from)].push_back(to);
        graph[0][opposite(to)].push_back(from);

        graph[1][to].push_back(opposite(from));
        graph[1][from].push_back(opposite(to));
    }

    if(is_sol(n)){
        for(int i=2;i<n;i+=2){
            cout<<res[i/2]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"No solution\n";
    }
return 0;
}