// Not solved - time limit with all optimizations I can think of

#include<iostream>
#include<string>
#include<utility>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=7;
pair<int,int> dirs[4]={{0,-1}, {0,1}, {-1,0}, {1,0}};
char letter[4]={'L', 'R', 'U', 'D'};
bool visited[MAXN][MAXN];
 
bool is_free(int x, int y){
    return (x>=0 and x<MAXN and y>=0 and y<MAXN and !visited[x][y]);
}
 
int dfs(int x, int y, char curr_dir, int ind, string& path){
    if(ind>-1 and path[ind]!='?' and curr_dir!=path[ind]){
        return 0;
    }
    
    if(x==MAXN-1 and y==0){
        if(ind+1==(int)path.size()){
            return 1;
        }
        return 0;
    }
    
    int free_col=is_free(x+1,y)+is_free(x-1,y);
    int free_row=is_free(x,y+1)+is_free(x,y-1);
    if((free_col==2 and free_row==0) or (free_col==0 and free_row==2)){
        return 0;
    }
 
    int res=0;
    for(int i=0;i<4;++i){
        int nextx=x+dirs[i].first;
        int nexty=y+dirs[i].second;
        
        if(is_free(nextx,nexty)){
            visited[nextx][nexty]=true;
            res+=dfs(nextx, nexty, letter[i], ind+1, path);
            visited[nextx][nexty]=false;
        }
    }
 
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string path;
    cin>>path;
 
    visited[0][0]=true;
    cout<<dfs(0, 0, ' ', -1, path)<<endl;
return 0;
}