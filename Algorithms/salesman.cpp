#include<iostream>
#include<vector>
#include<bitset>

#define endl '\n'

using namespace std;

const int INF=1e8;
vector<pair<int,int>> graph[18];
int dp[(1<<18)+3][18];

int dfs(int visited, int curr, int n){
    int& ans=dp[visited][curr];
    if(ans!=INF){
        return ans;
    }
    for(pair<int,int> next : graph[curr]){
        if(next.first==0 and visited==n-1){
            ans=next.second;
        }else if(next.first!=0 and !(visited & (1<<(next.first-1)))){
            ans=min(ans,next.second+dfs((visited | (1<<(next.first-1))),next.first,n));
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    cin>>tests;

    while(tests--){
        int n;
        cin>>n;

        for(int i=0;i<n;++i){
            for(int i2=i+1;i2<=n;++i2){
                int dist;
                cin>>dist;
                graph[i].push_back({i2,dist});
                graph[i2].push_back({i,dist});
            }
        }
        
        for(int i=0;i<(1<<n);++i){
            for(int i2=0;i2<=n;++i2){
                dp[i][i2]=1e8;
            }
        }

        cout<<dfs(0,0,(1<<n))<<endl;
    }
return 0;
}