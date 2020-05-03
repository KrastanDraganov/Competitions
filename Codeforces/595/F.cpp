#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=203;
vector<int> graph[MAXN];
int weights[MAXN],dp[MAXN][MAXN];

void dfs(int currv, int parent, int k, int n){
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv,k,n);
        }
    }

    dp[currv][0]=weights[currv];
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dp[currv][0]+=dp[nextv][k];
        }
    }
    for(int i=1;i<n;++i){
        for(int nextv : graph[currv]){
            if(nextv!=parent){
                int curr=dp[nextv][i-1];
                for(int secondv : graph[currv]){
                    if(secondv!=nextv and secondv!=parent){
                        curr+=dp[secondv][max(k-i,i-1)];
                    }
                }
                dp[currv][i]=max(dp[currv][i],curr);
            }
        }
    }
    for(int i=n-2;i>=0;--i){
        dp[currv][i]=max(dp[currv][i],dp[currv][i+1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>weights[i];
    }
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    dfs(0,-1,k,n);
    cout<<dp[0][0]<<endl;
return 0;
}