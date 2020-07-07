#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=103;
pair<int,int> dirs[4]={{-1,0},{1,0},{0,-1},{0,1}};
char board[MAXN][MAXN];
pair<int,int> next_ship[MAXN][MAXN][4],curr[MAXN][MAXN][4];

int direction(char spaceship){
    int res=-1;
    switch(spaceship){
        case '^':
            res=0;
            break;
        case 'v':
            res=1;
            break;
        case '<':
            res=2;
            break;
        case '>':
            res=3;
            break;
    }
    return res;
}

int calc_time(int x, int y, int n, int m){
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            for(int i3=0;i3<4;++i3){
                curr[i][i2][i3]=next_ship[i][i2][i3];
            }
        }
    }
    int time=0;
    while(true){
        int dir=direction(board[x][y]);
        if(curr[x][y][dir].first==-1){
            switch(dir){
                case 0:
                    time+=x+1;
                    break;
                case 1:
                    time+=n-x;
                    break;
                case 2:
                    time+=y+1;
                    break;
                case 3:
                    time+=m-y;
                    break;
            }
            break;
        }
        for(int i=0;i<4;++i){
            if(curr[x][y][i].first!=-1){
                int nextx=curr[x][y][i].first;
                int nexty=curr[x][y][i].second;
                curr[nextx][nexty][i^1]=curr[x][y][i^1];
            }
        }
        int newx=curr[x][y][dir].first;
        int newy=curr[x][y][dir].second;
        time+=abs(x-newx)+abs(y-newy);
        x=newx;
        y=newy;
    }
    return time;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>board[i][i2];
        }
    }

    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            for(int i3=0;i3<4;++i3){
                int x=i+dirs[i3].first;
                int y=i2+dirs[i3].second;
                next_ship[i][i2][i3]={-1,-1};
                while(x>=0 and x<n and y>=0 and y<m){
                    if(board[x][y]!='.'){
                        next_ship[i][i2][i3]={x,y};
                        break;
                    }
                    x+=dirs[i3].first;
                    y+=dirs[i3].second;
                }
            }
        }
    }

    int res=0;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            if(board[i][i2]!='.'){
                res=max(res,calc_time(i,i2,n,m));
            }
        }
    }
    cout<<res<<endl;
return 0;
}