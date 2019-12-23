#include<iostream>
#include<utility>
#include<iomanip>
#define endl '\n'
#define MAXN 5005
using namespace std;
struct node {
    int leafs,left,right;
} tree[MAXN];
int n,m;
double dp[MAXN][MAXN];
int dfs(int x){
    if(tree[x].left==-1){
        return tree[x].leafs=1;
    }
    return tree[x].leafs=dfs(tree[x].left)+dfs(tree[x].right);
}
double sol(int x, int counter){
    if(dp[x][counter]!=0.0) return dp[x][counter];
    if(tree[x].leafs==counter){
        return dp[x][counter]=1;
    }
    if(counter==0){
        return dp[x][counter]=0;
    }
    dp[x][counter]=-1;
    for(int i=max(0,counter-tree[tree[x].right].leafs);i<=min(counter,tree[tree[x].left].leafs);++i){
        double ansl=sol(tree[x].left,i),ansr=sol(tree[x].right,counter-i);
        double curr=(min(ansl,ansr)+2*max(ansl,ansr))/3;
        /*if(x==0 and counter==m){
            cout<<i<<" "<<curr<<endl;
        }*/
        if(curr>dp[x][counter]){
            dp[x][counter]=curr;
        }
    }
    return dp[x][counter];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>tree[i].left;
        if(tree[i].left!=-1){
            cin>>tree[i].right;
            --tree[i].right;
            --tree[i].left;
        }
    }
    dfs(0);
    cout<<fixed<<setprecision(10)<<sol(0,m)<<endl;
return 0;
}