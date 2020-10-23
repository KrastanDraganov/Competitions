#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[2][2*MAXN];
bool visited[2*MAXN],res[MAXN];
int component[2*MAXN];

void modify_val(int& num, char sign){
    num*=2;
    if(sign=='-'){
        ++num;
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
    m=2*m+2;

    for(int i=0;i<n;++i){
        int topping1,topping2;
        char is_good1,is_good2;
        cin>>is_good1>>topping1>>is_good2>>topping2;
        
        modify_val(topping1, is_good1);
        modify_val(topping2, is_good2);

        graph[0][opposite(topping1)].push_back(topping2);
        graph[0][opposite(topping2)].push_back(topping1);

        graph[1][topping2].push_back(opposite(topping1));
        graph[1][topping1].push_back(opposite(topping2));
    }

    if(is_sol(m)){
        for(int i=2;i<m;i+=2){
            cout<<(res[i/2] ? '+' : '-')<<" ";
        }
        cout<<endl;
    }else{
        cout<<"IMPOSSIBLE\n";
    }
return 0;
}