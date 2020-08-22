#include<iostream>

#define endl '\n'

using namespace std;

struct Directions {
    int left,right,up,down;
    Directions(){
        left=0;
        right=0;
        up=0;
        down=0;
    }
};

const int MAXN=1e3+3;
pair<int,int> dirs[4]={{0,-1},{0,1},{-1,0},{1,0}};
bool table[MAXN][MAXN];
Directions sum[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=m;++i2){
            char curr;
            cin>>curr;
            table[i][i2]=curr-'0';
            sum[i][i2].left=table[i][i2-1]*(sum[i][i2-1].left+1);
            sum[i][i2].up=table[i-1][i2]*(sum[i-1][i2].up+1);
        }
    }

    for(int i=n;i>0;--i){
        for(int i2=m;i2>0;--i2){
            sum[i][i2].right=table[i][i2+1]*(sum[i][i2+1].right+1);
            sum[i][i2].down=table[i+1][i2]*(sum[i+1][i2].down+1);
        }
    }

    int tests;
    cin>>tests;
    while(tests--){
        int x,y;
        cin>>x>>y;
        if(x==1 or x==n or y==1 or y==m){
            cout<<-1<<endl;
            continue;
        }
        int res=1+sum[x][y].left+sum[x][y].right+sum[x][y].up+sum[x][y].down;
        int around=0;
        for(int i=0;i<4;++i){
            around+=table[x+dirs[i].first][y+dirs[i].second];
        }
        if(around<3 or (around==3 and !table[x][y])){
            cout<<-1<<endl;
            continue;
        }else if(around==3){
            if(sum[x][y].left==0){
                res+=sum[x][y-1].left+1;
            }else if(sum[x][y].right==0){
                res+=sum[x][y+1].right+1;
            }else if(sum[x][y].up==0){
                res+=sum[x-1][y].up+1;
            }else if(sum[x][y].down==0){
                res+=sum[x+1][y].down+1;
            }
        }else if(table[x][y]){
            int max_bonus=0;
            if(y-sum[x][y].left-1>0){
                max_bonus=max(max_bonus,sum[x][y-sum[x][y].left-1].left+1);
            }
            if(y+sum[x][y].right+1<=m){
                max_bonus=max(max_bonus,sum[x][y+sum[x][y].right+1].right+1);
            }
            if(x-sum[x][y].up-1>0){
                max_bonus=max(max_bonus,sum[x-sum[x][y].up-1][y].up+1);
            }
            if(x+sum[x][y].down+1<=n){
                max_bonus=max(max_bonus,sum[x+sum[x][y].down+1][y].down+1);
            }
            res+=max_bonus;
        }
        cout<<res<<endl;
    }
return 0;
}