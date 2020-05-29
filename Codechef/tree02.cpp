#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e4+3;
vector<int> graph[MAXN];
long long weights[MAXN],all[MAXN];

int dfs(int currv, int parent, long long maxw){
    vector<long long> children;
    int cut_edges=0;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            cut_edges+=dfs(nextv,currv,maxw);
            children.push_back(all[nextv]);
        }
    }
    
    all[currv]=weights[currv];
    sort(children.begin(),children.end());
    cut_edges+=(int)children.size();
    for(long long weight : children){
        if(all[currv]+weight<=maxw){
            all[currv]+=weight;
            --cut_edges;
        }
    }
    return cut_edges;
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

    long long l=0,r=0;
    for(int i=0;i<n;++i){
        l=max(l,weights[i]);
        r+=weights[i];
    }
    while(l<=r){
        long long mid=(l+r)/2;
        if(dfs(0,-1,mid)<k){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<(r+1)<<endl;
return 0;
}