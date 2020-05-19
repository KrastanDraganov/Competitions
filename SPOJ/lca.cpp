#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1003,MAXL=13;
vector<int> graph[MAXN];
int lca[MAXN][MAXL],depth[MAXN];
bool is_child[MAXN];

void dfs(int currv, int parent){
    if(parent!=-1){
        depth[currv]=depth[parent]+1;
    }
    lca[currv][0]=parent;
    for(int i=1;i<MAXL and lca[currv][i-1]!=-1;++i){
        lca[currv][i]=lca[lca[currv][i-1]][i-1];
    }
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv);
        }
    }
}

int find_lca(int x, int y){
    if(depth[x]<depth[y]){
        swap(x,y);
    }
    for(int i=MAXL-1;i>=0;--i){
        if(lca[x][i]!=-1 and depth[lca[x][i]]>=depth[y]){
            x=lca[x][i];
        }
    }
    if(x==y){
        return x;
    }
    for(int i=MAXL-1;i>=0;--i){
        if(lca[x][i]!=lca[y][i]){
            x=lca[x][i];
            y=lca[y][i];
        }
    }
    return lca[x][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    for(int test=1;test<=tests;++test){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            graph[i].clear();
            is_child[i]=false;
            for(int i2=0;i2<MAXL;++i2){
                lca[i][i2]=-1;
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
        dfs(root,-1);

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