#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
vector<int> graph[MAXN],component[MAXN];
int degree[MAXN];
bool visited[MAXN];

void dfs(int currv, int id){
    visited[currv]=true;
    
    if(degree[currv] & 1){
        component[id].push_back(currv);
    }
    
    for(int nextv : graph[currv]){
        if(!visited[nextv]){
            dfs(nextv, id);
        }
    }
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
        
        ++degree[from];
        ++degree[to];
    }

    int counter=0;
    vector<int> odd,even;
    for(int i=0;i<n;++i){
        if(visited[i]){
            continue;
        }
        dfs(i, counter);
        
        if(component[counter].empty()){
            even.push_back(counter);
            component[counter].push_back(i);
        }else{
            odd.push_back(counter);
        }
        
        ++counter;
    }
    
    vector<pair<int, int>> res;
    if(!even.empty()){
        // connect even components in order to become one odd component
        if((int)even.size()>1){
            for(int i=1;i<(int)even.size();++i){
                res.push_back({component[even[i-1]][0], component[even[i]][0]});
            }

            int became_odd1=component[even[0]][0];
            int became_odd2=component[even.back()][0];
            
            ++degree[became_odd1];
            ++degree[became_odd2];
            
            component[even[0]].push_back(became_odd2);
        }
        
        odd.push_back(even[0]);
    }

    for(int i=1;i<(int)odd.size();++i){
        int odd_vertex1=component[odd[i-1]][1];
        int odd_vertex2=component[odd[i]][0];
        
        res.push_back({odd_vertex1, odd_vertex2});
        
        ++degree[odd_vertex1];
        ++degree[odd_vertex2];
    }

    int prev_odd=-1;
    for(int i=0;i<n;++i){
        if(!(degree[i] & 1)){
            continue;
        }
        
        if(prev_odd==-1){
            prev_odd=i;
            continue;
        }
        
        res.push_back({prev_odd, i});
        prev_odd=-1;
    }

    cout<<(int)res.size()<<endl;
    for(pair<int, int> curr : res){
        cout<<curr.first+1<<" "<<curr.second+1<<endl;
    }
return 0;
}