#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e4;
vector<int> graph[MAXN];
int visited[MAXN];

bool dfs(int currv){
    visited[currv]=1;

    bool is_cycle=false;
    for(int nextv : graph[currv]){
        if(visited[nextv]==1){
            return true;
        }

        if(visited[nextv]==0){
            is_cycle |= dfs(nextv);
        }
    }

    visited[currv]=2;

    return is_cycle;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin>>k;

    for(int i=0;i<k;++i){
        int n;
        cin>>n;

        int prev;
        cin>>prev;
        --prev;

        for(int j=1;j<n;++j){
            int curr;
            cin>>curr;
            --curr;
            graph[prev].push_back(curr);
            prev=curr;
        }
    }

    bool is_cycle=false;
    for(int i=0;i<MAXN;++i){
        if(visited[i]!=0){
            continue;
        }

        if(dfs(i)){
            is_cycle=true;
            break;
        }
    }

    cout<<!is_cycle<<endl;
return 0;
}