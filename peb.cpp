#include<iostream>
#include<algorithm>
#include<queue>
#define endl '\n'
using namespace std;
const int MAXN = (int) 1e6+3;
int level[MAXN];
queue<int> q;
bool pull(int x, int y){
    if(level[y]==0){
        q.push(y);
        level[y]=level[x]+1;
    }
}
void bfs(int start){
    q.push(start);
    level[start]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        int curra=curr/10000,currb=(curr%10000)/100,currc=curr%100,next;
        if(curra<=currb){
            next=20000*curra+100*(currb-curra)+currc;
            pull(curr,next);
        }
        if(curra<=currc){
            next=20000*curra+100*currb+currc-curra;
            pull(curr,next);
        }
        if(currb<=currc){
            next=10000*curra+200*currb+currc-currb;
            pull(curr,next);
        }
        if(curra>=currb){
            next=10000*(curra-currb)+200*currb+currc;
            pull(curr,next);
        }
        if(curra>=currc){
            next=10000*(curra-currc)+100*currb+2*currc;
            pull(curr,next);
        }
        if(currb>=currc){
            next=10000*curra+100*(currb-currc)+2*currc;
            pull(curr,next);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c;
    cin>>a>>b>>c;
    bfs(10000*a+100*b+c);
    cout<<level[a+b+c]-1<<endl;
return 0;
}