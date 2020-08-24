//Only 80/100 points

#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=103,MAXQ=1e7+3;
int graph[MAXN][MAXN],q_front=0,q_end=0;
pair<int,int> dirs[]={{0,-1},{0,1},{-1,0},{1,0}},q[MAXQ];

void push(int v,int v2) {
    q[q_end++]={v,v2};
}

pair<int,int> pop() {
    return q[q_front++];
}

int size() {
    return q_end-q_front;
}

int bfs(int x,int y, int n, int m){
    q_front=0;
    q_end=0;
    push(x,y);
    while(size()>0){
        pair<int,int>front=pop();
        int cx=front.first,cy=front.second;
        graph[cx][cy]=1;
        for(int i=0;i<4;i++){
            int cx2=cx+dirs[i].first,cy2=cy+dirs[i].second;
            if(cx2>-1 and cx2<n and cy2>-1 and cy2<m)
            if(graph[cx2][cy2]==0){
                push(cx2,cy2);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1]=1;
    }
    
    int res=0;
    for(int i=0;i<n;i++){
        for(int i2=0;i2<m;i2++){
            if(graph[i][i2]==0){
                bfs(i,i2,n,m);
                res++;
            }
        }
    }
    cout<<res<<endl;
return 0;
}
