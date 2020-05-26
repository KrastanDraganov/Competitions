#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MAXL=20;
vector<int> graph[MAXN];
int depth[MAXN],lca[MAXN][MAXL];

struct Path {
    int people[13];
    
    Path(){
        for(int i=0;i<13;++i){
            people[i]=1e9;
        }
    }

    void push_id(int id){
        int pos=10;
        for(int i=0;i<10;++i){
            if(id<people[i]){
                pos=i;
                break;
            }
        }
        for(int i=8;i>=pos;--i){
            swap(people[i+1],people[i]);
        }
        people[pos]=id;
    }

    void merge(Path comp){
        for(int i=0;i<10;++i){
            push_id(comp.people[i]);
        }
    }
} citizens[MAXN][MAXL];

void dfs(int currv, int parent, int curr_depth){
    depth[currv]=curr_depth;
    lca[currv][0]=parent;
    for(int i=1;i<MAXL and lca[currv][i-1]!=-1;++i){
        lca[currv][i]=lca[lca[currv][i-1]][i-1];
        citizens[currv][i]=citizens[currv][i-1];
        citizens[currv][i].merge(citizens[lca[currv][i-1]][i-1]);
    }
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv,curr_depth+1);
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

Path calc_path(int city, int dist){
    Path res;
    for(int i=0;i<MAXL;++i){
        if((1<<i) & dist){
            res.merge(citizens[city][i]);
            city=lca[city][i];
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<MAXL;++i2){
            lca[i][i2]=-1;
        }
    }
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i=0;i<m;++i){
        int city;
        cin>>city;
        --city;
        citizens[city][0].push_id(i);
    }

    dfs(0,-1,0);
    while(q--){
        int x,y,a;
        cin>>x>>y>>a;
        --x;
        --y;
        
        int curr=find_lca(x,y);
        Path res1=calc_path(x,depth[x]-depth[curr]+1);
        Path res2=calc_path(y,depth[y]-depth[curr]);
        res1.merge(res2);
        int k=0;
        for(int i=0;i<a and res1.people[i]<m;++i){
            ++k;
        }
        
        cout<<k<<" ";
        for(int i=0;i<k;++i){
            cout<<res1.people[i]+1<<" ";
        }
        cout<<endl;
    }
return 0;
}