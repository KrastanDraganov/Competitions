#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
vector<int> graph[MAXN];
int weights[MAXN],dp[MAXN],res[MAXN];

void dfs(int currv, int parent){
    dp[currv]=weights[currv];
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv);
            dp[currv]=max(dp[currv],dp[nextv]+weights[currv]);
        }
    }
}

void dfs2(int currv, int parent, int prev){
    res[currv]=max(dp[currv],prev+weights[currv]);
    int max1=0,max2=0;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            int sum=dp[nextv]+weights[currv];
            if(sum>max1){
                max2=max1;
                max1=sum;
            }else if(sum>max2){
                max2=sum;
            }
        }
    }
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            int sum=dp[nextv]+weights[currv],new_prev=prev+weights[currv];
            if(sum==max1){
                new_prev=max(new_prev,max2);
            }else{
                new_prev=max(new_prev,max1);
            }
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
    int m;
    cin>>m;
    while(m--){
        int city,grade;
        cin>>city>>grade;
        --city;
        weights[city]=grade;
    }

    dfs(0,-1);
    dfs2(0,-1,0);
    int t;
    cin>>t;
    while(t--){
        int city;
        cin>>city;
        --city;
        cout<<res[city]-weights[city]<<" ";
    }
    cout<<endl;
return 0;
}