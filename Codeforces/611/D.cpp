#include<iostream>
#include<queue>
#include<map>
#include<vector>
#define endl '\n'
using namespace std;
vector<int> people;
map<int,int> dist;
queue<int> bfs;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        int tree;
        cin>>tree;
        dist[tree]=0;
        bfs.push(tree);
    }
    long long ans=0;
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        if(dist[curr]){
            ans+=(long long)dist[curr];
            people.push_back(curr);
            if(people.size()==m){
                break;
            }
        }
        if(!dist.count(curr-1)){
            dist[curr-1]=dist[curr]+1;
            bfs.push(curr-1);
        }
        if(!dist.count(curr+1)){
            dist[curr+1]=dist[curr]+1;
            bfs.push(curr+1);
        }
    }
    cout<<ans<<endl;
    for(int curr : people){
        cout<<curr<<" ";
    }
    cout<<endl;
return 0;
}