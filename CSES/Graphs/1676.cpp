#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int parent[MAXN],depth[MAXN];

int find_parent(int currv){
    if(currv==parent[currv]){
        return currv;
    }
    return parent[currv]=find_parent(parent[currv]);
}


bool are_combined(int x, int y, int& largest_comp){
    int root1=find_parent(x),root2=find_parent(y);
    if(root1==root2){
        return true;
    }
    
    if(depth[root1]<depth[root2]){
        swap(root1, root2);
    }
    
    parent[root2]=root1;
    depth[root1]+=depth[root2];
    largest_comp=max(largest_comp, depth[root1]);
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        parent[i]=i;
        depth[i]=1;
    }

    int all_comps=n,largest_comp=1;
    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;

        if(!are_combined(from, to, largest_comp)){
            --all_comps;
        }
        
        cout<<all_comps<<" "<<largest_comp<<endl;
    }
return 0;
}