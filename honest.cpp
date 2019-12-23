#include<bits/stdc++.h>
#define endl '\n'
#define MAXN 10005
using namespace std;
vector<pair<int,int>>graph[MAXN];
int statement[MAXN],visited[MAXN],st_end,lies[MAXN],trues[MAXN];
pair<int,pair<int,int>>st[MAXN];
void dfs(int x,int counter,int h){
    st_end=0;
    st[st_end++]={x,{counter,h}};
    while(st_end>0){
        pair<int,pair<int,int>>curr=st[--st_end];
        visited[curr.first]=curr.second.first;
        statement[curr.first]=curr.second.second;
        for(int i=0;i<graph[curr.first].size();i++){
            int next1=graph[curr.first][i].first,next2=graph[curr.first][i].second;
            if(visited[next1]==0){
                st[st_end++]={next1,{counter,curr.second.second*next2}};
                visited[next1]=curr.second.first;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,z;
        char c;
        cin>>x>>c>>y;
        x--; y--;
        if(c=='h') z=1;
        else z=-1;
        graph[x].push_back({y,z});
        graph[y].push_back({x,z});
    }
    int counter=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i,counter,1);
            counter++;
        }
    }
    int result=0;
    for(int i=0;i<n;i++){
        lies[visited[i]]++;
        if(statement[i]==1) trues[visited[i]]++;
    }
    for(int i=1;i<counter;i++){
        if(trues[i]>lies[i]-trues[i]){
            result+=trues[i];
        }else{
            result+=lies[i]-trues[i];
        }
    }
    cout<<result<<endl;
return 0;
}