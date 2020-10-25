#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>

#define endl '\n'

using namespace std;

const int MAXN=2e3+3;
pair<int, int> points[MAXN];
int dist[MAXN][MAXN],component[2*MAXN];
vector<int> graph[2*MAXN];
bool visited[2*MAXN];

int square(int num){
    return num*num;
}

int calc_dist(int ind1, int ind2){
    return square(points[ind1].first-points[ind2].first)
            +square(points[ind1].second-points[ind2].second);
}

int opposite(int ind, int n){
    return n+ind;
}

void dfs(int currv, vector<int>& topo){
    visited[currv]=true;
    for(int nextv : graph[currv]){
        if(!visited[nextv]){
            dfs(nextv, topo);
        }
    }
    topo.push_back(currv);
}

void dfs2(int currv, int id){
    component[currv]=id;
    for(int nextv : graph[currv]){
        if(component[nextv]==-1){
            dfs2(nextv, id);
        }
    }
}

bool can_divide(int dist_limit, int n){
    for(int i=0;i<2*n;++i){
        graph[i].clear();
        visited[i]=false;
        component[i]=-1;
    }

    for(int i=0;i<n;++i){
        for(int i2=i+1;i2<n;++i2){
            if(dist[i][i2]>dist_limit){
                graph[i].push_back(opposite(i2, n));
                graph[opposite(i, n)].push_back(i2);
                
                graph[i2].push_back(opposite(i, n));
                graph[opposite(i2, n)].push_back(i);
            }
        }
    }

    vector<int> topo;
    for(int i=0;i<2*n;++i){
        if(!visited[i]){
            dfs(i, topo);
        }
    }

    int counter=0;
    for(int i=2*n-1;i>=0;--i){
        if(component[topo[i]]==-1){
            dfs2(topo[i], counter++);
        }
    }
    
    for(int i=0;i<n;++i){
        if(component[i]==component[opposite(i, n)]){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        points[i]={x, y};
    }

    int max_dist=0;
    for(int i=0;i<n;++i){
        for(int i2=i+1;i2<n;++i2){
            dist[i][i2]=dist[i2][i]=calc_dist(i, i2);
            max_dist=max(max_dist, dist[i][i2]);
        }
    }

    int l=0,r=max_dist;
    while(l<=r){
        int mid=(l+r)/2;
        if(can_divide(mid, n)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    double res=sqrt(l);
    cout<<fixed<<setprecision(6)<<res<<endl;
return 0;
}