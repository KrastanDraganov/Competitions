#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1003;
vector<int> graph[MAXN];
int lca[MAXN][32],depth[MAXN];

void dfs(int curr, int parent, int curr_depth){
   depth[curr]=curr_depth;
   lca[curr][0]=parent;
   for(int nextv : graph[curr]){
      if(nextv!=parent){
         dfs(nextv,curr,curr_depth+1);
      }
   }
}

void calc_lca(int max_power, int n){
    for(int i=1;i<=n;++i){
        for(int i2=0;i2<n;++i2){
            lca[i2][i]=lca[lca[i2][i-1]][i-1];
        }
    }
}

int find_lca(int x, int y, int max_power){
    if(depth[x]<depth[y]){
        swap(x,y);
    }
    int diff=depth[x]-depth[y];
    for(int i=max_power;diff>0;--i){
        if(diff%2==1){
            x=lca[x][i];
        }
        diff/=2;
    }
    if(x==y){
        return x;
    }
    for(int i=max_power;i>=0;--i){
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
         depth[i]=0;
         for(int i2=0;i2<30;++i2){
            lca[i][i2]=0;
         }
      }
      for(int i=0;i<n;++i){
         int children;
         cin>>children;
         for(int i2=0;i2<children;++i2){
            int to;
            cin>>to;
            --to;
            graph[i].push_back(to);
            graph[to].push_back(i);
         }
      }
      dfs(0,0,0);
      int max_power=0;
      while((1<<max_power)<=n){
        ++max_power;
      }
      --max_power;
      calc_lca(max_power,n);
      int q;
      cin>>q;
      cout<<"Case "<<test<<":\n";
      while(q--){
         int x,y;
         cin>>x>>y;
         --x;
         --y;
         cout<<find_lca(x,y,max_power)+1<<endl;
      }
   }
return 0;
}