#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=5e4+3,MAXK=103,MOD=1e9+7;
vector<int> graph[MAXN];
int k,weights[MAXN],dp[MAXN][MAXK];

int mul(int num1, int num2){
    return (long long) num1*num2%MOD;
}

void dfs(int currv, int parent){
    dp[currv][0]=1;
    dp[currv][weights[currv]]=1;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv);
            for(int i=weights[currv];i<=k;++i){
                dp[currv][i]=(dp[currv][i]+dp[nextv][i-weights[currv]])%MOD;
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
        int n;
        cin>>n>>k;
        for(int i=0;i<n;++i){
            cin>>weights[i];
            graph[i].clear();
            for(int i2=0;i2<=k;++i2){
                dp[i][i2]=0;
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
        int res=0;
        for(int i=0;i<n;++i){
            cout<<i<<": "<<dp[i][k]<<endl;
            res=(res+dp[i][k])%MOD;
        }
        cout<<res<<endl;
    }
return 0;
}