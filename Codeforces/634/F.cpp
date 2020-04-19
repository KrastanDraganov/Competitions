#include<iostream>
#include<vector>
#include<utility>
#include<map>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int n,m;
vector<int> graph[MAXN],cycle;
map<char,pair<int,int>> dirs;
char dir[MAXN];
bool color[MAXN],used1[MAXN],used2[MAXN],is_black[MAXN];

int move_robot(char curr, int x, int y){
    return (x+dirs[curr].first)*m+y+dirs[curr].second;
}

void dfs1(int currv){
    if(used1[currv]){
        cycle.push_back(currv);
        return;
    }
    used1[currv]=true;
    int next_ind=move_robot(dir[currv],currv/m,currv%m);
    dfs1(next_ind);
    if(cycle.back()==next_ind and cycle[0]!=currv){
        cycle.push_back(currv);
    }
}

void dfs2(int currv, int depth){
    used2[currv]=true;
    if(color[currv]){
        is_black[depth%((int)cycle.size())]=true;
    }
    for(int nextv : graph[currv]){
        if(!used2[nextv]){
            dfs2(nextv,depth+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    dirs['L']={0,-1};
    dirs['R']={0,1};
    dirs['U']={-1,0};
    dirs['D']={1,0};
    while(tests--){
        cin>>n>>m;
        for(int i=0;i<n;++i){
            for(int i2=0;i2<m;++i2){
                graph[i*m+i2].clear();
                used1[i*m+i2]=false;
                used2[i*m+i2]=false;
            }
        }
        for(int i=0;i<n;++i){
            for(int i2=0;i2<m;++i2){
                char curr;
                cin>>curr;
                color[i*m+i2]=!(curr-'0');
            }
        }
        for(int i=0;i<n;++i){
            for(int i2=0;i2<m;++i2){
                cin>>dir[i*m+i2];
                int next_ind=move_robot(dir[i*m+i2],i,i2);
                graph[next_ind].push_back(m*i+i2);
            }
        }

        int all_robots=0,black_cells=0;
        for(int i=0;i<n;++i){
            for(int i2=0;i2<m;++i2){
                if(!used2[i*m+i2]){
                    cycle.clear();
                    dfs1(i*m+i2);
                    all_robots+=(int)cycle.size();
                    for(int i3=0;i3<cycle.size();++i3){
                        is_black[i3]=false;
                    }
                    dfs2(cycle[0],0);
                    for(int i3=0;i3<cycle.size();++i3){
                        black_cells+=is_black[i3];
                    }
                }
            }
        }
        cout<<all_robots<<" "<<black_cells<<endl;
    }
return 0;
}