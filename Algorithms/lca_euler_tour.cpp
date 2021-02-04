#include<iostream>
#include<vector>
#include<climits>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3,MAXL=20;
vector<int> graph[MAXN];
pair<int, int> rmq[2*MAXN][MAXL];
int first_meet[MAXN],log2[2*MAXN];

void dfs(int currv, int parent, int depth, vector<pair<int, int>>& euler_tour){
    euler_tour.push_back({depth, currv});

    if(first_meet[currv]==-1){
        first_meet[currv]=(int)euler_tour.size()-1;
    }

    for(int nextv : graph[currv]){
        if(nextv==parent){
            continue;
        }

        dfs(nextv, currv, depth+1, euler_tour);
        euler_tour.push_back({depth, currv});
    }
}

void calc_rmq(vector<pair<int, int>>& euler_tour){
    for(int i=0;i<2*MAXN;++i){
        for(int j=0;j<MAXL;++j){
            rmq[i][j]={INT_MAX, -1};
        }
    }

    int n=(int)euler_tour.size();
    for(int i=2;i<=n;++i){
        log2[i]=log2[i/2]+1;
    }
    
    for(int i=0;i<n;++i){
        rmq[i][0]=euler_tour[i];
    }

    for(int range=1;range<=log2[n];++range){
        for(int i=0;i+(1<<range)<=n;++i){
            int j=i+(1<<(range-1));
            rmq[i][range]=min(rmq[i][range-1], rmq[j][range-1]);
        }
    }
}

int query(int x, int y){
    x=first_meet[x];
    y=first_meet[y];
    
    if(x>y){
        swap(x, y);
    }

    int range=log2[y-x+1];
    pair<int, int> res=min(rmq[x][range], rmq[y-(1<<range)+1][range]);

    return res.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int currv=0;currv<n;++currv){
        int m;
        cin>>m;

        for(int i=0;i<m;++i){
            int nextv;
            cin>>nextv;

            graph[currv].push_back(nextv);
        }
    }

    for(int i=0;i<n;++i){
        first_meet[i]=-1;
    }

    vector<pair<int, int>> euler_tour;
    dfs(0, -1, 0, euler_tour);

    calc_rmq(euler_tour);

    int q;
    cin>>q;

    while(q--){
        int x,y;
        cin>>x>>y;

        cout<<query(x, y)<<endl;
    }
return 0;
}