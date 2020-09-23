#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1003,MAXL=20;
vector<int> graph[MAXN];
vector<pair<int,int>> euler;
pair<int,int> rmq[3*MAXN][MAXL];
int first_meet[MAXN],log[3*MAXN];
bool is_child[MAXN];

void dfs(int currv, int parent, int depth){
    euler.push_back({depth,currv});
    if(first_meet[currv]==-1){
        first_meet[currv]=(int)euler.size()-1;
    }
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv,depth+1);
            euler.push_back({depth,currv});
        }
    }
}

void calc_rmq(int n){
    for(int i=0;i<n;++i){
        rmq[i][0]=euler[i];
    }
    for(int i=1;i<MAXL;++i){
        for(int i2=0;i2<n;++i2){
            int i3=i2+(1<<(i-1));
            rmq[i2][i]=(i3<n ? min(rmq[i2][i-1],rmq[i3][i-1]) : rmq[i2][i-1]);
        }
    }
}

int find_lca(int x, int y){
    x=first_meet[x];
    y=first_meet[y];
    if(x>y){
        swap(x,y);
    }
    int diff=y-x+1;
    if(diff==1){
        return rmq[x][0].second;
    }
    int curr_log=log[diff];
    return min(rmq[x][curr_log-1],rmq[y-(1<<(curr_log-1))+1][curr_log-1]).second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    log[1]=0;
    for(int i=2;i<3*MAXN;++i){
        log[i]=log[i/2]+1;
    }
    int tests;
    cin>>tests;
    for(int test=1;test<=tests;++test){
        int n;
        cin>>n;
        euler.clear();
        for(int i=0;i<n;++i){
            graph[i].clear();
            is_child[i]=false;
            first_meet[i]=-1;
        }
        for(int i=0;i<3*MAXN;++i){
            for(int i2=0;i2<MAXL;++i2){
                rmq[i][i2]={1e9,1e9};
            }
        }
        for(int i=0;i<n;++i){
            int m;
            cin>>m;
            while(m--){
                int child;
                cin>>child;
                --child;
                graph[i].push_back(child);
                is_child[child]=true;
            }
        }
        
        int root=-1;
        for(int i=0;i<n;++i){
            if(!is_child[i]){
                root=i;
                break;
            }
        }
        dfs(root,-1,0);
        calc_rmq((int)euler.size());

        int q;
        cin>>q;
        cout<<"Case "<<test<<":\n";
        while(q--){
            int x,y;
            cin>>x>>y;
            --x;
            --y;
            cout<<find_lca(x,y)+1<<endl;
        }
    }
return 0;
}