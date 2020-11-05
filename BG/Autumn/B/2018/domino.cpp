// Not solved - 10 points, wrong answer

#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=(1<<10)+3;
int graph[MAXN][MAXN],degree[MAXN];

void dfs(int currv, int n, vector<int>& euler_path){
    for(int nextv=0;nextv<=n;++nextv){
        if(graph[currv][nextv]==0){
            continue;
        }
        // cout<<"dfs: "<<currv<<" -> "<<nextv<<" "<<graph[currv][nextv]<<endl;
        --graph[currv][nextv];
        --graph[nextv][currv];
        dfs(nextv, n, euler_path);
    }
    // cout<<"no edges: "<<currv<<endl;

    euler_path.push_back(currv);
}

vector<vector<int>> find_chains(int n){
    vector<vector<int>> res;

    int prev_odd=-1;
    for(int i=0;i<=n;++i){
        // cout<<"degree of "<<i<<": "<<degree[i]<<endl;
        
        if(!(degree[i] & 1)){
            continue;
        }

        if(prev_odd==-1){
            prev_odd=i;
            continue;
        }

        ++graph[prev_odd][i];
        ++graph[i][prev_odd];

        // cout<<"odd: "<<prev_odd<<" "<<i<<endl;

        vector<int> curr_chain;
        dfs(i, n, curr_chain);
        curr_chain.pop_back();
        res.push_back(curr_chain);

        prev_odd=-1;
    }

    if(res.empty()){
        vector<int> curr_chain;
        dfs(0, n, curr_chain);
        res.push_back(curr_chain);
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<=n;++i){
        for(int i2=i;i2<=n;++i2){
            ++graph[i][i2];
            ++graph[i2][i];

            ++degree[i];
            ++degree[i2];
        }
    }

    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;

        --graph[from][to];
        --graph[to][from];

        --degree[from];
        --degree[to];
    }

    vector<vector<int>> res=find_chains(n);

    cout<<(int)res.size()<<endl;
    for(vector<int> chain : res){
        for(int curr : chain){
            cout<<curr<<" ";
        }
        cout<<-1<<endl;
    }
return 0;
}