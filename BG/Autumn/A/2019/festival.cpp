// Not solved - 57 points, time limit

#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=4e3+3;
pair<int, int> concerts[MAXN][2];
vector<int> graph[2][2*MAXN];
int component[2*MAXN];
bool visited[2*MAXN],res[MAXN];

bool is_intersection(const pair<int, int>& concert1, const pair<int, int>& concert2){
    return (concert1.first <= concert2.first and concert2.first <= concert1.second)
        or (concert1.first <= concert2.second and concert2.second <= concert1.second)
        or (concert2.first <=concert1.first and concert1.first <= concert2.second)
        or (concert2.first <= concert1.second and concert1.second <= concert2.second);
}

void dfs1(int currv, vector<int>& topo){
    visited[currv]=true;
    for(int nextv : graph[0][currv]){
        if(!visited[nextv]){
            dfs1(nextv, topo);
        }
    }
    topo.push_back(currv);
}

void dfs2(int currv, int id){
    component[currv]=id;
    for(int nextv : graph[1][currv]){
        if(component[nextv]==-1){
            dfs2(nextv, id);
        }
    }
}

bool is_solution(int n){
    vector<int> topo;
    for(int i=0;i<2*n;++i){
        if(!visited[i]){
            dfs1(i, topo);
        }
    }

    for(int i=0;i<2*n;++i){
        component[i]=-1;
    }

    int counter=0;
    for(int i=2*n-1;i>=0;--i){
        if(component[topo[i]]==-1){
            dfs2(topo[i], counter++);
        }
    }

    for(int i=0;i<n;++i){
        if(component[2*i]==component[2*i+1]){
            return false;
        }
        res[i]=(component[2*i]>component[2*i+1]);
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    for(int i=0;i<n;++i){
        for(int i2=0;i2<2;++i2){
            int start_time,end_time;
            cin>>start_time>>end_time;
            concerts[i][i2]={start_time, end_time};
        }
    }

    for(int x=0;x<n;++x){
        for(int y=x+1;y<n;++y){
            for(int i=0;i<2;++i){
                for(int i2=0;i2<2;++i2){
                    if(is_intersection(concerts[x][i], concerts[y][i2])){
                        graph[0][2*y+(i2^1)].push_back(2*x+i);
                        graph[0][2*x+(i^1)].push_back(2*y+i2);

                        graph[1][2*x+i].push_back(2*y+(i2^1));
                        graph[1][2*y+i2].push_back(2*x+(i^1));
                    }
                }
            }
        }
    }

    if(!is_solution(n)){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
        for(int i=0;i<n;++i){
            cout<<(res[i] ? 2 : 1)<<endl;
        }
    }
return 0;
}