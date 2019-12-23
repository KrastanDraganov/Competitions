#include<bits/stdc++.h>
#define N 100005
#define INF 1<<30
using namespace std;
long long dep[N];
priority_queue<pair<int,int>> bfs;
vector<pair<int,int>> ch[N];
int main(){
    int a,b,x,y,z,curr,rez=0;
    cin>>a>>b;
    for(int i=0;i<b;i++){
        cin>>x>>y>>z;
        ch[x].push_back({y,z});
        ch[y].push_back({x,z});
    }
    cin>>x;
    for(int i=0;i<=a;i++) dep[i]=INF;
    bfs.push({0,1});
    dep[1]=0;
    while(!bfs.empty()){
        curr=bfs.top().second;
        bfs.pop();
        cout<<curr<<endl;;
        for(int i=0;i<ch[curr].size();i++){
            //cout<<i<<" "<<curr<<" "<<ch[curr][i3].first<<" "<<dep[ch[curr][i3].first]<<endl;
            if(dep[curr]+ch[curr][i].second<dep[ch[curr][i].first]){
                //cout<<curr<<" "<<ch[curr][i3].first<<" "<<dep[curr]<<endl;
                dep[ch[curr][i].first]=dep[curr]+ch[curr][i].second;
                bfs.push({-dep[ch[curr][i].first],ch[curr][i].first});
            }
        }
    }
    for(int i=1;i<=a;i++){
        cout<<dep[i]<<" ";
        if(dep[i]>x){
            rez++;
        }
    }
    cout<<rez<<endl;
return 0;
}