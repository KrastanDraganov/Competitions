#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];
int res[MAXN];

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
        graph[from].push_back(i);
        graph[to].push_back(i);
        res[i]=-1;
    }
    pair<int,int> max_degree={0,0};
    for(int i=0;i<n;++i){
        pair<int,int> curr={graph[i].size(),i};
        max_degree=max(max_degree,curr);
    }
    int counter=0;
    for(int ind : graph[max_degree.second]){
        res[ind]=counter++;
    }
    for(int i=1;i<n;++i){
        if(res[i]==-1){
            res[i]=counter++;
        }
        cout<<res[i]<<endl;
    }
return 0;
}