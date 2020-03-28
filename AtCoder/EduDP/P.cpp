#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MOD=1e9+7;
vector<int> graph[MAXN];

int mul(int x, int y){
    return (long long)x*y%MOD;
}

pair<int,int> dfs(int currv, int parent){
    int white=1,black=0;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            pair<int,int> res=dfs(nextv,currv);
            int copy_white=white;
            white=mul(white,res.second);
            black=(mul(copy_white,res.first)+mul(black,res.first+res.second))%MOD;
        }
    }
    return {white,(white+black)%MOD};
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

    pair<int,int> res=dfs(0,-1);
    res.first=(res.first+res.second)%MOD;
    cout<<res.first<<endl;

return 0;
}