#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
vector<int> graph[MAXN];

pair<int,int> dfs(int currv, int parent){
    int res=0,max_depth1=0,max_depth2=0;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            pair<int,int> curr=dfs(nextv,currv);
            ++curr.second;
            res=max(res,curr.first);
            if(curr.second>max_depth1){
                max_depth2=max_depth1;
                max_depth1=curr.second;
            }else if(curr.second>max_depth2){
                max_depth2=curr.second;
            }
        }
    }
    res=max(res,max_depth1+max_depth2);
    return {res,max_depth1};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    cout<<dfs(0,-1).first<<endl;
return 0;
}