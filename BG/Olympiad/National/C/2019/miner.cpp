#include<iostream>
#include<utility>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
pair<int,int>dirs[]={{0,-1},{0,1},{1,0},{-1,0},{1,-1},{1,1},{-1,-1},{-1,1}};
char mine[MAXN][MAXN];
bool used[MAXN][MAXN];
int checker[MAXN][MAXN];

void bfs(int x, int y, int n, int& clicks){
    queue<pair<int,int>> q;
    q.push({x,y});
    
    int counter=0;
    while(!q.empty()){
        counter++;
        int qx=q.front().first,qy=q.front().second;
        used[qx][qy]=true;
        q.pop();
        
        bool is_bomb=false;
        for(int i=0;i<8;i++){
            int curr_x=qx+dirs[i].first,curr_y=qy+dirs[i].second;
            if(curr_x>-1 and curr_y>-1 and curr_x<n and curr_y<n){
                if(mine[curr_x][curr_y]=='@'){
                    is_bomb=true;
                    break;
                }
            }
        }
        
        if(is_bomb){
            break;
        }

        for(int i=0;i<8;i++){
            int curr_x=qx+dirs[i].first,curr_y=qy+dirs[i].second;
            if(curr_x>-1 and curr_y>-1 and curr_x<n and curr_y<n){
                if(!used[curr_x][curr_y]){
                    q.push({curr_x,curr_y});
                    used[curr_x][curr_y]=true;
                }else if(checker[curr_x][curr_y]==1){
                    clicks--;
                    checker[curr_x][curr_y]=2;
                }
            }
        }
    }
    
    if(counter==1){
        checker[x][y]=1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int i2=0;i2<n;i2++){
            cin>>mine[i][i2];
        }
    }
    
    int clicks=0;
    for(int i=0;i<n;i++){
        for(int i2=0;i2<n;i2++){
            if(!used[i][i2] and mine[i][i2]=='.'){
                bfs(i,i2,n,clicks);
                clicks++;
            }
        }
    }
    cout<<clicks<<endl;
return 0;
}