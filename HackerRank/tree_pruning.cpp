#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,MAXK=203;
vector<int> graph[MAXN];
int k;
long long weights[MAXN],dp[MAXN][MAXK];

void dfs(int currv, int parent){
    dp[currv][0]=weights[currv];
    vector<int> children;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv);
            children.push_back(nextv);
            dp[currv][0]+=dp[nextv][0];
        }
    }

    for(int i=1;i<=k;++i){
        for(int child : children){
            dp[currv][i]=max(dp[currv][i],dp[currv][i-1]-dp[child][i-1]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>weights[i];
        for(int i2=0;i2<=k;++i2){
            dp[i][i2]=-1e9+3;
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

    dfs(0,-1);
    long long res=0;
    for(int i=0;i<=k;++i){
        res=max(res,dp[0][i]);
    }
    cout<<res<<endl;
return 0;
}