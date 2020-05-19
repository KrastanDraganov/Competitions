#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
vector<int> graph[MAXN];
int dp[2][MAXN];

void dfs(int currv, int parent){
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv);
            dp[0][currv]=max(dp[0][currv],dp[0][nextv]+1);
        }
    }
}

void dfs2(int currv, int parent, int prev){
    dp[1][currv]=prev;
    int max_depth1=0,max_depth2=0;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            int sum=dp[0][nextv]+2;
            if(sum>max_depth1){
                max_depth2=max_depth1;
                max_depth1=sum;
            }else{
                max_depth2=sum;
            }
        }
    }
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            int sum=dp[0][nextv]+2;
            int new_prev=max(prev+1,(sum==max_depth1 ? max_depth2 : max_depth1));
            dfs2(nextv,currv,new_prev);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    dfs(0,-1);
    dfs2(0,-1,0);
    int res=0;
    for(int i=0;i<n;++i){
        res=max(res,dp[0][i]+dp[1][i]);
    }
    cout<<res<<endl;
return 0;
}