#include<bits/stdc++.h>
#define N 505
using namespace std;
queue<pair<int,int>> bfs;
stack<pair<int,int>> k;
int dep[N][N],graph[N][N];
pair<int,int> dirs[]={{0,-1},{0,1},{-1,0},{1,0}},parent[N][N];
char parents2[N][N];
int main(){
    int n,m,x,y,rez=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int i2=0;i2<m;i2++){
            cin>>graph[i][i2];
       }
    }
    cin>>x>>y;
    bfs.push({x,y});
    dep[x][y]=1;
    int destx,desty;
    while(!bfs.empty()){
        int a=bfs.front().first,b=bfs.front().second;
        for(int i=0;i<4;i++){
            int ca=a+dirs[i].first,cb=b+dirs[i].second;
            if(ca>-1 and ca<n and cb>-1 and cb<m)
            if(dep[ca][cb]==0 and graph[ca][cb]==0){
                dep[ca][cb]=dep[a][b]+1;
                parent[ca][cb]={a,b};
                char direction;
                switch(i){
                    case 0: direction='l';
                    break;
                    case 1: direction='r';
                    break;
                    case 2: direction='u';
                    break;
                    case 3: direction='d';
                    break;
                }
                parents2[ca][cb]=direction;
                if(ca==0 or cb==0 or ca==n-1 or cb==m-1){
                    destx=ca;
                    desty=cb;
                }
                bfs.push({ca,cb});
            }
        }
        bfs.pop();
    }
    k.push({destx,desty});
    pair<int,int> cord=parent[destx][desty],cord2={x,y};
    while(cord!=cord2){
        k.push(cord);
        cord=parent[cord.first][cord.second];
    }
    while(!k.empty()){
        int rezx=k.top().first,rezy=k.top().second;
        //cout<<rezx<<" "<<rezy<<endl;
        cout<<parents2[rezx][rezy];
        k.pop();
    }
    cout<<endl;
return 0;
}