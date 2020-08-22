#include<iostream>
#include<queue>
#include<cstring>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=53;
pair<int,int> dirs[4]={{0,-1},{0,1},{-1,0},{1,0}};
string table[MAXN];
bool used[MAXN][MAXN][MAXN];

struct Vertex {
    int row,col,ind;
    Vertex(){}
    Vertex(int _row, int _col, int _ind){
        row=_row;
        col=_col;
        ind=_ind;
    }
};

bool ans(string s, int n, int m){
    memset(used,0,sizeof(used));
    queue<Vertex> bfs;
    
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            if(table[i][i2]==s[0]){
                if(s.size()==1){
                    return true;
                }
                used[i][i2][0]=true;
                bfs.push(Vertex(i,i2,1));
            }
        }
    }
    
    while(!bfs.empty()){
        Vertex curr=bfs.front();
        bfs.pop();
        for(int i=0;i<4;++i){
            int newx=curr.row+dirs[i].first,newy=curr.col+dirs[i].second;
            if(newx>=0 and newx<n and newy>=0 and newy<m){
                if(table[newx][newy]==s[curr.ind]){
                    if(curr.ind==s.size()-1) return true;
                    if(!used[newx][newy][curr.ind+1]){
                        used[newx][newy][curr.ind+1]=true;
                        bfs.push(Vertex(newx,newy,curr.ind+1));
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>table[i];
    }
    
    int k;
    cin>>k;
    for(int i=0;i<k;++i){
        string s;
        cin>>s;
        cout<<(ans(s,n,m) ? "Yes" : "No")<<endl;
    }
return 0;
}