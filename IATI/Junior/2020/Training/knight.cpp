#include<iostream>
#include<utility>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=4,MAXM=5;
const int ALL_CELLS=MAXN*MAXM;
pair<int, int> horse_dirs[8]={{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
bool used[MAXN][MAXM];
vector<vector<int>> res;

bool check(int x, int y){
    return x>=0 and x<MAXN and y>=0 and y<MAXM and !used[x][y];
}

void calc_solutions(int currx, int curry, vector<pair<int, int>>& path){
    if((int)path.size()==ALL_CELLS-1){
        vector<int> curr(ALL_CELLS);
        curr[currx*MAXM+curry]=ALL_CELLS;

        for(int i=0;i<ALL_CELLS-1;++i){
            int x=path[i].first;
            int y=path[i].second;
            curr[x*MAXM+y]=i+1;
        }
        res.push_back(curr);

        return;
    }

    used[currx][curry]=true;
    path.push_back({currx, curry});

    for(int i=0;i<8;++i){
        int nextx=currx+horse_dirs[i].first;
        int nexty=curry+horse_dirs[i].second;

        if(check(nextx, nexty)){
            calc_solutions(nextx, nexty, path);
        }
    }

    used[currx][curry]=false;
    path.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int x=0;x<MAXN;++x){
        for(int y=0;y<MAXM;++y){
            vector<pair<int, int>> path;
            calc_solutions(x, y, path);
        }
    }

    cout<<(int)res.size()<<endl;
    for(vector<int> path : res){
        for(int curr : path){
            cout<<curr<<" ";
        }
        cout<<endl;
    }
return 0;
}
