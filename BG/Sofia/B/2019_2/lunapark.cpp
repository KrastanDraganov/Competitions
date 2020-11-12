#include<iostream>
#include<vector>
#include<stack>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3,MAXL=20;
vector<pair<int,int>> graph[MAXN];
bool used[MAXN];
int logarithm[MAXN],rmq[MAXN][MAXL];
int initial_pos[MAXN],cycle_pos[MAXN],root_dist[MAXN];

bool dfs1(int currv, int parent, stack<pair<int, int>>& path, vector<pair<int, int>>& cycle){
    used[currv]=true;
    
    for(pair<int,int> nextv : graph[currv]){
        if(nextv.first==parent){
            continue;
        }
        
        if(used[nextv.first]){
            cycle.push_back(nextv);
            while(path.top().first!=nextv.first){
                cycle.push_back(path.top());
                path.pop();
            }
            return true;
        }
        
        path.push(nextv);
        if(dfs1(nextv.first, currv, path, cycle)){
            return true;
        }
        path.pop();
    }
    
    return false;
}

void dfs2(int currv){
    used[currv]=true;
    for(pair<int,int> nextv : graph[currv]){
        if(!used[nextv.first]){
            root_dist[nextv.first]=max(nextv.second, root_dist[currv]);
            cycle_pos[nextv.first]=cycle_pos[currv];
            dfs2(nextv.first);
        }
    }
}

void calc_rmq(vector<pair<int, int>>& cycle){
    logarithm[1]=0;
    for(int i=2;i<MAXN;++i){
        logarithm[i]=logarithm[i/2]+1;
    }
    
    int n=(int) cycle.size();
    for(int i=0;i<n;++i){
        rmq[i][0]=cycle[i].second;
    }
    
    for(int range=1;range<MAXL;++range){
        for(int i=0;i+(1<<range)<=n;++i){
            rmq[i][range]=max(rmq[i][range-1], rmq[i+(1<<(range-1))][range-1]);
        }
    }
}

long long query(int l, int r){
    if(l>r){
        return 0;
    }
    int range=logarithm[r-l+1];
    return max(rmq[l][range], rmq[r-(1<<range)+1][range]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        --from;
        --to;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
    
    vector<pair<int, int>> cycle;
    stack<pair<int, int>> path;
    path.push({0, 0});
    dfs1(0, -1, path, cycle);

    for(int i=0;i<n;++i){
        initial_pos[i]=i;
        used[i]=false;
    }

    int m=(int) cycle.size();
    for(int i=0;i<m;++i){
        cycle_pos[cycle[i].first]=i;
        used[cycle[i].first]=true;
    }
    for(pair<int,int> curr : cycle){
        dfs2(curr.first);
    }
    calc_rmq(cycle);
    
    int q;
    cin>>q;
    
    long long res=0;
    while(q--){
        int type,x,y;
        cin>>type>>x>>y;
        --x;
        --y;

        if(type==2){
            swap(initial_pos[x], initial_pos[y]);
            continue;
        }
        
        x=initial_pos[x];
        y=initial_pos[y];
        long long max_dist=max(root_dist[x], root_dist[y]);
        
        x=cycle_pos[x];
        y=cycle_pos[y];
        if(x>y){
            swap(x,y);
        }
        long long res1=max(max_dist, query(x, y-1));
        long long res2=max(max_dist, max(query(0, x-1), query(y, m-1)));
        
        if(res2>res1){
            swap(res1,res2);
        }
        res+=2*res1+res2;
    }
    
    cout<<res<<endl;
return 0;
}
