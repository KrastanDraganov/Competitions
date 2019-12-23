#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1005];
bool j[1005];
int checker[1005];
void dfs(int y,int br2){
    queue<pair<int,int>>q;
    q.push({y,br2});
    while(!q.empty()){
        int x=q.front().first,br=q.front().second;
        j[x]=true;
        checker[x]=br;
        q.pop();
        for(int i2=0;i2<graph[x].size();i2++){
            if(!j[graph[x][i2]]){
                q.push({graph[x][i2],br});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int counter=1;
    for(int i=1;i<=n;i++){
        if(!j[i]){
            dfs(i,counter);
            counter++;
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(checker[a]==checker[b]){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    cout<<endl;
return 0;
}
