#include<iostream>
#include<vector>
#include<utility>
#define endl '\n'
#define MAXK 205
using namespace std;
int k;
pair<int,int> dirs[]={{1,-1},{-1,0},{0,-1},{1,0},{0,1},{-1,1}};
vector<int> graph[2*MAXK][2*MAXK];
bool visited[2*MAXK][2*MAXK];
int get_dir(int x){
    switch(x){
        case 1 : return 3;
        case 2 : return 4;
        case 4 : return 5;
        case 8 : return 1;
        case 16 : return 2;
        case 32 : return 0;
        default : return 69;
    }
}
void build_edge(int x, int row, int col){
    if(x<=0){
        return;
    }
    if(x>31){
        graph[row][col].push_back(get_dir(32));
        build_edge(x-32, row, col);
    }else if(x>15){
        graph[row][col].push_back(get_dir(16));
        build_edge(x-16, row, col);
    }else if(x>7){
        graph[row][col].push_back(get_dir(8));
        build_edge(x-8, row, col);
    }else if(x>3){
        graph[row][col].push_back(get_dir(4));
        build_edge(x-4, row, col);
    }else if(x>1){
        graph[row][col].push_back(get_dir(2));
        build_edge(x-2, row, col);
    }else{
        graph[row][col].push_back(get_dir(1));
    }
}
bool check(int x, int y, int oldx, int oldy){
    bool is_path=false;
    for(int next : graph[x][y]){
        int newx=x+dirs[next].first,newy=y+dirs[next].second;
        if(newx>=0 and newx<(2*k-1) and newy>=0 and newy<(2*k-1)){
            if(newx==oldx and newy==oldy){
                is_path=true;
                break;
            }
        }
    }
    if(x<k){
        return (is_path and x>=0 and x<(2*k-1) and y>=(k-x-1) and y<(2*k-1));
    }else{
        return (is_path and x>=0 and x<(2*k-1) and y>=0 and y<(3*k-2-x));
    }
}
int dfs(int x, int y){
    int counter=0;
    for(int next : graph[x][y]){
        int newx=x+dirs[next].first,newy=y+dirs[next].second;
        if(check(newx,newy,x,y)){
            if(!visited[newx][newy]){
                //cout<<"("<<newx<<","<<newy<<") ";
                visited[newx][newy]=true;
                counter+=(dfs(newx,newy)+1);
            }
        }
    }
    return counter;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int start_col=0,end_col=3;
    cin>>k;
    for(int i=2*k-2;i>=0;--i){
        for(int i2=start_col;i2<end_col;++i2){
            int cord;
            cin>>cord;
            build_edge(cord,i,i2);
        }
        if(i>=k){
            ++end_col;
        }else{
            ++start_col;
        }
    }
    start_col=0;
    end_col=3;
    int res=-1;
    for(int i=2*k-2;i>=0;--i){
        for(int i2=start_col;i2<end_col;++i2){
            /*cout<<i<<" "<<i2<<": ";
            for(int test : graph[i][i2]){
                cout<<test<<" ";
            }
            cout<<endl;*/
            if(!visited[i][i2]){
                visited[i][i2]=true;
                //cout<<i<<" "<<i2<<": ";
                int curr=dfs(i,i2)+1;
                //cout<<", res: "<<curr<<endl;
                res=max(res,curr);
            }
        }
        if(i>=k){
            ++end_col;
        }else{
            ++start_col;
        }
    }
    cout<<res<<endl;
return 0;
}
