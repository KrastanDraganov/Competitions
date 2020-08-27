//Only 0/100 points

#include<iostream>
#include<vector>
#include<stack>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
vector<pair<int,int>> graph[MAXN],cycle;
bool used[MAXN];
int orig_pos[MAXN],cycle_pos[MAXN],root_dist[MAXN],logarithm[MAXN],rmq[MAXN][20];
stack<pair<int,int>> path;

bool dfs1(int curr, int parent){
    used[curr]=true;
    for(pair<int,int> next : graph[curr]){
        if(next.first==parent){
            continue;
        }
        if(used[next.first]){
            cycle.push_back(next);
            while(path.top().first!=next.first){
                cycle.push_back(path.top());
                path.pop();
            }
            return true;
        }
        path.push(next);
        if(dfs1(next.first,curr)){
            return true;
        }
        path.pop();
    }
    return false;
}

void dfs2(int curr){
    used[curr]=true;
    for(pair<int,int> next : graph[curr]){
        if(!used[next.first]){
            root_dist[next.first]=max(next.second,root_dist[curr]);
            cycle_pos[next.first]=cycle_pos[curr];
            dfs2(next.first);
        }
    }
}

void calc_rmq(int n){
    logarithm[1]=0;
    for(int i=2;i<=n;++i){
        logarithm[i]=logarithm[i/2]+1;
    }
    for(int i=0;i<cycle.size();++i){
        rmq[i][0]=cycle[i].second;
    }
    for(int i=1;i<20;++i){
        for(int i2=0;i2<cycle.size();++i2){
            int i3=i2+(1<<(i-1));
            rmq[i2][i]=(i3<cycle.size() ? max(rmq[i2][i-1],rmq[i3][i-1]) : rmq[i2][i-1]);
        }
    }
}

long long query(int l, int r){
    if(l>r){
        return 0;
    }
    int diff=r-l+1;
    if(diff==1){
        return rmq[l][0];
    }
    return max(rmq[l][logarithm[diff]-1],rmq[r-(1<<(logarithm[diff]-1))+1][logarithm[diff]-1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int from,to,weight;
        cin>>from>>to>>weight;
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }
    
    path.push({1,0});
    dfs1(1,0);

    for(int i=1;i<=n;++i){
        orig_pos[i]=i;
        used[i]=false;
    }
    
    for(int i=0;i<cycle.size();++i){
        cycle_pos[cycle[i].first]=i;
        used[cycle[i].first]=true;
    
    }
    for(pair<int,int> curr : cycle){
        dfs2(curr.first);
    }
    calc_rmq(n);
    
    int q;
    cin>>q;
    long long ans=0;
    for(int i=0;i<q;++i){
        int type,x,y;
        cin>>type>>x>>y;
        if(type==1){
            x=orig_pos[x];
            y=orig_pos[y];
            long long max_dist=max(root_dist[x],root_dist[y]);
            x=cycle_pos[x];
            y=cycle_pos[y];
            if(x>y){
                swap(x,y);
            }
            long long res1=max(max_dist,query(x,y-1));
            long long res2=max(max_dist,max(query(0,x-1),query(y,cycle.size()-1)));
            if(res2>res1){
                swap(res1,res2);
            }
            ans+=2ll*res1+res2;
        }else{
            swap(orig_pos[x],orig_pos[y]);
        }
    }
    cout<<ans<<endl;
return 0;
}
