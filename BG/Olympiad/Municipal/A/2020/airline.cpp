#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];
int dp[MAXN],res[MAXN];

void dfs(int currv, int parent){
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv);
            dp[currv]=max(dp[currv],dp[nextv]+1);
        }
    }
}

void dfs2(int currv, int parent, int prev){
    res[currv]=max(dp[currv],prev);
    int max1=0,max2=0;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            int sum=dp[nextv]+2;
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
            int sum=dp[nextv]+2,new_prev=prev+1;
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

    dfs(0,-1);
    dfs2(0,-1,0);
    vector<int> closest;
    int min_dist=1e9;
    for(int i=0;i<n;++i){
        if(res[i]<min_dist){
            closest.clear();
            min_dist=res[i];
        }
        if(res[i]==min_dist){
            closest.push_back(i+1);
        }
    }
    
    cout<<(int)closest.size()<<endl;
    for(int city : closest){
        cout<<city<<" ";
    }
    cout<<endl;
return 0;
}