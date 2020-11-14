// Not solved - 20 points, time limit

#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=5e4+3,MAXM=2e5+3;
pair<int, int> edges[MAXM];
int parent[MAXN],depth[MAXN];

int find_parent(int currv){
    if(currv==parent[currv]){
        return currv;
    }
    return parent[currv]=find_parent(parent[currv]);
}

bool are_combined(int x, int y){
    int root1=find_parent(x),root2=find_parent(y);
    
    if(root1==root2){
        return true;
    }

    if(depth[root1]<depth[root2]){
        swap(root1, root2);
    }
    parent[root2]=root1;
    depth[root1]+=depth[root2];

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        edges[i]={from, to};
    }

    int res=0;
    for(int i=0;i<m;++i){
        for(int i=0;i<n;++i){
            parent[i]=i;
            depth[i]=1;
        }

        int components=n;
        for(int i2=i;i2<m;++i2){
            int from=edges[i2].first;
            int to=edges[i2].second;

            if(!are_combined(from, to)){
                --components;
            }

            if(components==1){
                res+=(m-i2);
                break;
            }
        }
    }

    cout<<res<<endl;
return 0;
}