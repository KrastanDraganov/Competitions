#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=5e4+3;
vector<int> graph[MAXN],barns;
int farthest[MAXN],barn[MAXN];

int dfs(int currv, int parent, int max_dist){
    if(currv==0){
        barns.clear();
        for(int i=0;i<MAXN;++i){
            farthest[i]=0;
            barn[i]=MAXN;
        }
    }

    int counter=0;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            counter+=dfs(nextv,currv,max_dist);
            farthest[currv]=max(farthest[currv],farthest[nextv]+1);
            barn[currv]=min(barn[currv],barn[nextv]+1);
        }
    }

    if(farthest[currv]+barn[currv]<=max_dist){
        farthest[currv]=-1;
    }
    if((currv==0 and farthest[currv]!=-1) or farthest[currv]>=max_dist){
        ++counter;
        barns.push_back(currv);
        barn[currv]=0;
        farthest[currv]=-1;
    }
    return counter;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(dfs(0,-1,mid)<=m){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    int res=r+1;
    dfs(0,-1,res);
    for(int i=0;i<n and barns.size()<m;++i){
        if(barn[i]!=0){
            barns.push_back(i);
        }
    }

    cout<<res<<endl;
    for(int curr : barns){
        cout<<curr+1<<" ";
    }
    cout<<endl;
return 0;
}