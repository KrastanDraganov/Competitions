#include<bits/stdc++.h>
#define N 100005
using namespace std;
int dep[N];
queue<int> bfs;
stack<int> k;
vector<int> ch[N];
int parent[1001];
int main(){
    int a,b,x,y,curr,rez=0;
    cin>>a>>b;
    for(int i=0;i<b;i++){
        cin>>x>>y;
        ch[x].push_back(y);
        ch[y].push_back(x);
    }
    cin>>x>>y;
    bfs.push(x);
    dep[x]=1;
    bool j=false;
    parent[a]=-1;
    while(!bfs.empty()){
        curr=bfs.front();
        //cout<<curr<<" ";
        for(int i=0;i<ch[curr].size();i++){
            if(dep[ch[curr][i]]==0){
                dep[ch[curr][i]]=dep[curr]+1;
                if(ch[curr][i]==y){
                        j=true;
                        rez=dep[ch[curr][i]];
                }
                parent[ch[curr][i]]=curr;
                bfs.push(ch[curr][i]);
            }
        }
        bfs.pop();
    }
    if(j){
        k.push(y);
        curr=parent[y];
        while(curr!=x){
            k.push(curr);
            curr=parent[curr];
        }
        k.push(x);
        while(!k.empty()){
            cout<<k.top()<<" ";
            k.pop();
        }
        cout<<endl;
    }else cout<<-1<<endl;
return 0;
}
