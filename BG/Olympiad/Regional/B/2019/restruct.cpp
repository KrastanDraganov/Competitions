#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3;
vector<int> graph[MAXN];

int find_min_depth(int startv, int n){
    queue<int> bfs;
    bfs.push(startv);

    vector<int> depth(n, 0);
    depth[startv]=1;

    int sum_depths=0,visited=0;
    while(!bfs.empty()){
        int currv=bfs.front();
        bfs.pop();

        sum_depths+=depth[currv];
        ++visited;
        
        for(int nextv : graph[currv]){
            if(depth[nextv]==0){
                depth[nextv]=depth[currv]+1;
                bfs.push(nextv);
            }
        }
    }

    return (visited<n ? -1 : sum_depths);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    for(int currv=0;currv<n;++currv){
        int wanted;
        cin>>wanted;
        for(int i=0;i<wanted;++i){
            int boss;
            cin>>boss;
            --boss;
            graph[boss].push_back(currv);
        }
    }

    long long res=1e18;
    for(int i=0;i<n;++i){
        int min_depth=find_min_depth(i, n);
        if(min_depth!=-1){
            res=min(res, 1ll*min_depth*k);
        }
    }

    cout<<res<<endl;
return 0;
}