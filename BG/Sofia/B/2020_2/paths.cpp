#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=5e4+3,MAXL=17;
vector<int> graph[MAXN];
int lca[MAXN][MAXL],depth[MAXN],visits[MAXN];

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
            dfs(nextv, currv);
        }
    }
}

int find_lca(int x, int y){
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

int calc_visits(int currv, int parent){
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            visits[currv]+=calc_visits(nextv, currv);
        }
    }
    return visits[currv];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for(int i=0;i<n;++i){
        for(int i2=0;i2<MAXL;++i2){
            lca[i][i2]=-1;
        }
    }
    dfs(0, -1);

    for(int i=0;i<k;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;

        if(depth[from]<depth[to]){
            swap(from, to);
        }
        int meet_point=find_lca(from, to);

        ++visits[from];
        if(meet_point!=0){
            --visits[lca[meet_point][0]];
        }
        if(to!=meet_point){
            ++visits[to];
            --visits[meet_point];
        }
    }

    calc_visits(0, -1);

    int res=0;
    for(int i=0;i<n;++i){
        res=max(res, visits[i]);
    }
    cout<<res<<endl;
return 0;
}