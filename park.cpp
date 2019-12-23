#include<iostream>
#include<utility>
#define endl '\n'
#define MAXN 5
using namespace std;
const int MOD = 1e9+7;
pair<int,int> dirs[4]={{0,-1},{0,1},{-1,0},{1,0}};
bool used[MAXN][MAXN];
void dfs(int x, int y, int mask, int n, int m){
    used[x][y]=true;
    for(pair<int,int> next : dirs){
        int nextx=x+next.first,nexty=y+next.second;
        if(nextx>=0 and nextx<n and nexty>=0 and nexty<m){
            if(((1<<(m*nextx+nexty)) & mask) and !used[nextx][nexty]){
                dfs(nextx,nexty,mask,n,m);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int pow=1;
    for(int i=0;i<n*m;++i){
        pow*=2;
    }
    int counter=0;
    for(int i=0;i<pow;++i){
        bool check=false,check2=false;
        for(int x=0;x<n;++x){
            for(int y=0;y<m;++y){
                used[x][y]=false;
            }
        }
        for(int x=0;x<n;++x){
            for(int y=0;y<m;++y){
                if(((1<<(m*x+y)) & i) and !used[x][y]){
                    if(check){
                        check=false;
                        break;
                    }
                    dfs(x,y,i,n,m);
                    check=true;
                }
            }
        }
        for(int i2=0;i2<n;++i2){
            if(1<<(n*i2+m-1) & i){
                check2=true;
                break;
            }
        }
        counter+=(check and check2);
    }
    cout<<counter<<endl;
return 0;
}