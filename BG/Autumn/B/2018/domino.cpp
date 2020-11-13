// Not solved - 85 points, time limit

#include<iostream>
#include<vector>
#include<stack>

#define endl '\n'

using namespace std;

const int MAXN=(1<<10)+3;
int graph[MAXN][MAXN],degree[MAXN];
bool used[MAXN],fake_edge[MAXN][MAXN];

vector<int> find_euler_path(int startv, int n){
    stack<int> dfs;
    dfs.push(startv);
    
    vector<int> euler_path;
    while(!dfs.empty()){
        int currv=dfs.top();
        used[currv]=true;

        bool is_edge=false;
        for(int nextv=0;nextv<=n;++nextv){
            if(graph[currv][nextv]==0){
                continue;
            }
            is_edge=true;

            --graph[currv][nextv];
            --graph[nextv][currv];

            dfs.push(nextv);
            break;
        }

        if(!is_edge){
            euler_path.push_back(currv);
            dfs.pop();
        }
    }

    return euler_path;
}

void print_chain(vector<int>& chain){
    cout<<"chain: \n";
    for(int curr : chain){
        cout<<curr<<" ";
    }
    cout<<endl;
}

vector<vector<int>> remove_fake_edges(vector<int>& chain){
    int n=(int) chain.size();
    
    // Make chain start and end in vertices 
    // with odd degree if they exists
    for(int i=0;i+1<n;++i){
        if(!fake_edge[chain[i]][chain[i+1]]){
            continue;
        }
        
        fake_edge[chain[i]][chain[i+1]]=false;
        fake_edge[chain[i+1]][chain[i]]=false;
        
        vector<int> new_chain;
        for(int i2=i+1;i2<n;++i2){
            new_chain.push_back(chain[i2]);
        }
        for(int i2=1;i2<=i;++i2){
            new_chain.push_back(chain[i2]);
        }
        
        chain=new_chain;
        break;
    }
    
    vector<vector<int>> res;
    vector<int> curr_chain;
    
    n=(int) chain.size();
    for(int i=0;i<n;++i){
        curr_chain.push_back(chain[i]);
        if(i+1<n and fake_edge[chain[i]][chain[i+1]]){
            fake_edge[chain[i]][chain[i+1]]=false;
            fake_edge[chain[i+1]][chain[i]]=false;
            res.push_back(curr_chain);
            curr_chain.clear();
        }
    }
    res.push_back(curr_chain);
    
    return res;
}

vector<vector<int>> find_chains(int n){
    int prev_odd=-1;
    for(int i=0;i<=n;++i){
        if(!(degree[i] & 1)){
            continue;
        }

        if(prev_odd==-1){
            prev_odd=i;
            continue;
        }
        
        ++graph[prev_odd][i];
        ++graph[i][prev_odd];
        fake_edge[prev_odd][i]=fake_edge[i][prev_odd]=true;
        
        prev_odd=-1;
    }

    vector<vector<int>> res;
    for(int i=0;i<=n;++i){
        if(used[i] or degree[i]==0){
            continue;
        }
        
        vector<int> curr_chain=find_euler_path(i, n);
        
        vector<vector<int>> divided=remove_fake_edges(curr_chain);
        res.insert(res.end(), divided.begin(), divided.end());
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