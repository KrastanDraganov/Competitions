#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN=2e5+3;
int parent[MAXN],degree[MAXN];
bool not_leaf[MAXN];
vector<pair<int,int>> scheme;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i){
        cin>>parent[i];
        not_leaf[parent[i]]=true;
        ++degree[parent[i]];
    }
    priority_queue<int,vector<int>,greater<int>> leafs;
    for(int i=1;i<=n;++i){
        if(!not_leaf[i]){
            leafs.push(i);
        }
        ++degree[i];
    }
    for(int i=n-2;i>=0;--i){
        int curr=leafs.top();
        leafs.pop();
        scheme.push_back({curr,parent[i]});
        --degree[curr];
        --degree[parent[i]];
        if(degree[curr]==1){
            leafs.push(curr);
        }
        if(degree[parent[i]]==1){
            leafs.push(parent[i]);
        }
    }
    cout<<parent[0]<<endl;
    for(pair<int,int> wire : scheme){
        cout<<wire.first<<" "<<wire.second<<endl;
    }
return 0;
}