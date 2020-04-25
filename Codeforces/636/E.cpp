#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
vector<int> graph[MAXN];
long long prices[MAXN],prefix[MAXN];
int dist[MAXN][3];

void calc_dist(int startp, int ind){
    queue<int> bfs;
    bfs.push(startp);
    dist[startp][ind]=0;
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        for(int nextp : graph[curr]){
            if(dist[nextp][ind]==-1){
                dist[nextp][ind]=dist[curr][ind]+1;
                bfs.push(nextp);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,m,a,b,c;
        cin>>n>>m>>a>>b>>c;
        --a;
        --b;
        --c;
        for(int i=0;i<n;++i){
            graph[i].clear();
        }
        for(int i=0;i<m;++i){
            cin>>prices[i];
        }
        for(int i=0;i<m;++i){
            int from,to;
            cin>>from>>to;
            --from;
            --to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        sort(prices,prices+m);
        for(int i=0;i<m;++i){
            prefix[i+1]=prefix[i]+prices[i];
        }
        for(int i=0;i<3;++i){
            for(int i2=0;i2<n;++i2){
                dist[i2][i]=-1;
            }
        }
        calc_dist(a,0);
        calc_dist(b,1);
        calc_dist(c,2);
        long long res=1e18;
        for(int i=0;i<n;++i){
            int sum=0;
            for(int i2=0;i2<3;++i2){
                sum+=dist[i][i2];
            }
            if(sum<=m){
                res=min(res,prefix[sum]+prefix[dist[i][1]]);
            }
        }
        cout<<res<<endl;
    }
return 0;
}