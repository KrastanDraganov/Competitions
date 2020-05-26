#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];
int dp[MAXN],res[MAXN];
bool affected[MAXN];

int real(int dist, int type){
    if(dist==-1){
        return -1;
    }
    return dist+type;
}

void dfs(int currv, int parent){
    dp[currv]=(affected[currv] ? 0 : -1);
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv);
            if(dp[nextv]!=-1){
                dp[currv]=max(dp[currv],dp[nextv]+1);
            }
        }
    }
}

void dfs2(int currv, int parent, int prev){
    res[currv]=max(dp[currv],prev);
    int max1=-1,max2=-1;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            int curr=real(dp[nextv],2);
            if(curr>max1){
                max2=max1;
                max1=curr;
            }else if(curr>max2){
                max2=curr;
            }
        }
    }
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            int curr=real(dp[nextv],2),new_prev=real(prev,1);
            if(curr==max1){
                new_prev=max(new_prev,max2);
            }else{
                new_prev=max(new_prev,max1);
            }
            if(affected[nextv]){
                new_prev=max(new_prev,0);
            }
            dfs2(nextv,currv,new_prev);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,d;
    cin>>n>>m>>d;
    for(int i=0;i<m;++i){
        int curr;
        cin>>curr;
        --curr;
        affected[curr]=true;
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
    dfs2(0,-1,(affected[0] ? 0 : -1));

    int counter=0;
    for(int i=0;i<n;++i){
        counter+=(res[i]<=d);
    }
    cout<<counter<<endl;
return 0;
}