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
 
int dfs(int x, int y, int ind, string& path){
    if(x==MAXN-1 and y==0){
        if(ind==(int)path.size()){
            return 1;
        }
        return 0;
    }
 
    int res=0;
    for(int i=0;i<4;++i){
        int nextx=x+dirs[i].first;
        int nexty=y+dirs[i].second;
        
        if(is_free(nextx,nexty) and (path[ind]=='?' or letter[i]==path[ind])){
            bool is_locked=true;
            
            // are we moving to another column or row that block a part of the table
            if(i<2){
                is_locked &= !is_free(nextx, nexty+dirs[i].second);
                is_locked &= is_free(nextx-1, nexty);
                is_locked &= is_free(nextx+1, nexty);
            }else{
                is_locked &= !is_free(nextx+dirs[i].first, nexty);
                is_locked &= is_free(nextx, nexty-1);
                is_locked &= is_free(nextx, nexty+1);
            }

            if(is_locked){
                continue;
            }

            visited[nextx][nexty]=true;
            res+=dfs(nextx, nexty, ind+1, path);
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
    cout<<dfs(0, 0, 0, path)<<endl;
return 0;
}