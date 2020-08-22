#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=12;
pair<int,int> dirs[]={{0,-1},{0,1},{-1,0},{1,0}};
int table[MAXN][MAXN];

bool check(int x, int y, int n, int m){
    return (x>=0 and x<n and y>=0 and y<m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>table[i][i2];
        }
    }
    
    int res=-1;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            for(pair<int,int> next : dirs){
                int x=i+next.first,y=i2+next.second;
                for(pair<int,int> next2 : dirs){
                    int newx=x+next2.first,newy=y+next2.second;
                    if(check(x,y,n,m) and check(newx,newy,n,m) and !(newx==i and newy==i2)){
                        if(table[i][i2]+table[x][y]+table[newx][newy]>res){
                            res=table[i][i2]+table[x][y]+table[newx][newy];
                        }
                    }
                }
            }
        }
    }
    cout<<res<<endl;
return 0;
}