#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
vector<int> graph[MAXN];
int nums[MAXN],res[MAXN];

void dfs(int currv, int parent, int all, set<int> prev){
    if(currv==0){
        res[currv]=nums[currv];
    }else{
        res[currv]=all;
    }
    set<int> gcds;
    for(int curr : prev){
        int possible=__gcd(nums[currv],curr);
        res[currv]=max(res[currv],possible);
        gcds.insert(possible);
    }
    gcds.insert(all);
    all=__gcd(all,nums[currv]);
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv,all,gcds);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    set<int> starting;
    dfs(0,-1,0,starting);
    for(int i=0;i<n;++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
return 0;
}