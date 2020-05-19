#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
vector<int> graph[MAXN];

//<needed extra robots,max depth>
pair<int,int> dfs(int currv, int parent){
    int robots=0,normal=0,max_depth=0;
    bool is_left=true,is_larger=false;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            pair<int,int> info=dfs(nextv,currv);
            robots+=info.first;
            int depth=info.second+1;
            if(depth>1){
                if(normal==0){
                    is_left=!is_left;
                }
                robots+=is_larger;
                is_larger=true;
                normal=0;
            }else{
                ++normal;
            }
            max_depth=max(max_depth,depth);
        }
    }
    robots+=(is_left and is_larger and normal>0);
    //cout<<currv<<" "<<robots<<" "<<max_depth<<endl;
    return {robots,max_depth};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            graph[i].clear();
        }
        for(int i=1;i<n;++i){
            int from,to;
            cin>>from>>to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        cout<<1+dfs(0,-1).first<<endl;
    }
return 0;
}