#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<pair<long long,long long>>graph[N];
bool infect_city[N],infect_road[30005][30005],used[N],used2[N];
int bfs(int x){
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int y=q.front();
        used[y]=true;
        q.pop();
        for(int i=0;i<graph[y].size();i++){
            int cury=graph[y][i].first;
            if(infect_city[cury]==false and infect_road[y][cury]==false and used[cury]==false){
                q.push(cury);
            }
        }
    }
}
int count_components(int cities){
    int br=0;
    memset(used,0,N);
    for(int i=1;i<=cities;i++){
        for(int i2=0;i2<graph[i].size();i2++){
            int curc=graph[i][i2].first;
            if(infect_city[curc]==false and used[curc]==false){
                bfs(curc);
                br++;
            }
        }
    }
    return br;
}
int infect_cities(int city){
    int rezf=0;
    for(int i=0;i<graph[city].size();i++){
        int cur_city=graph[city][i].first;
        if(!infect_city[cur_city]){
            infect_city[cur_city]=true;
            infect_road[city][cur_city]=true;
            infect_road[cur_city][city]=true;
            rezf++;
        }
    }
    return rezf;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,l;
        cin>>u>>v>>l;
        graph[u].push_back({v,l});
        graph[v].push_back({u,l});
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int city;
        cin>>city;
        infect_city[city]=true;
    }
    int rez=-1,curr;
    while(m<n){
        curr=count_components(n);
        if(curr>rez) rez=curr;
        for(int i=1;i<=n;i++){
            if(infect_city[i]){
                m+=infect_cities(i);
            }
        }
    }
    cout<<rez+2<<endl;
return 0;
}