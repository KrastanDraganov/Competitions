#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
int parent[MAXN],depth[MAXN];
int find_parent(int num){
    if(num==parent[num]){
        return num;
    }
    return parent[num]=find_parent(parent[num]);
}
int combine(int num1, int num2){
    int root1=find_parent(num1),root2=find_parent(num2);
    if(root1!=root2){
        if(depth[root2]>depth[root1]){
            swap(root1,root2);
        }
        parent[root2]=root1;
        depth[root1]+=depth[root2];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            depth[i]=1;
            parent[i]=i;
        }
        bool is_res=(n==1);
        int res=(n==1 ? 0 : -1);
        for(int i=0;i<m;++i){
            int from,to;
            cin>>from>>to;
            combine(from,to);
            if(depth[find_parent(from)]==n and !is_res){
                res=i+1;
                is_res=true;
            }
        }
        cout<<res<<endl;
    }
return 0;
}