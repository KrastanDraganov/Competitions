#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=5e4+3,MAXK=503;
vector<int> graph[MAXN];
int dp[MAXN][MAXK],parent[MAXN];

void dfs(int currv, int prev, int k){
    dp[currv][0]=1;
    parent[currv]=prev;
    for(int nextv : graph[currv]){
        if(nextv!=prev){
            dfs(nextv,currv,k);
            for(int i=1;i<=k;++i){
                dp[currv][i]+=dp[nextv][i-1];
            }
        }
    }
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

    dfs(0,-1,k);
    int res=0;
    for(int currv=0;currv<n;++currv){
        int curr=0;
        for(int nextv : graph[currv]){
            if(nextv!=parent[currv]){
                for(int i=0;i<k-1;++i){
                    curr+=(dp[currv][k-i-1]-dp[nextv][k-i-2])*dp[nextv][i];
                }
            }
        }
        res+=(curr/2)+dp[currv][k];
    }
    cout<<res<<endl;
return 0;
}