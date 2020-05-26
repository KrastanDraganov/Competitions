#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
vector<int> graph[MAXN];

pair<int,int> dfs(int currv, int parent){
    int counter[3]={0},robots=0,type=-1;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            pair<int,int> info=dfs(nextv,currv);
            robots+=info.first;
            ++counter[info.second];
        }
    }
    robots+=(counter[2]/2);
    if(counter[2]%2==1 or (counter[1]>0 and counter[2]==0)){
        type=2;
    }else{
        type=(counter[2]>0 ? 0 : 1);
    }
    if(parent==-1 and type==2){
        ++robots;
    }
    return {robots,type};
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

        cout<<dfs(0,-1).first<<endl;
    }
return 0;
}