#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector <int> a[1001],wht[1001],ans[1001][1001];
int used[1001],orig[1001],st;
int dfs (int vr, int max1) {
    if (used[vr]==1) return 0;
    ans[st][vr].push_back(max1);
    int i;
    used[vr]=1;
    for (i=0; i<a[vr].size(); i++) {
        dfs(a[vr][i],max(max1,wht[vr][i]));
        }
    used[vr]=0;
}
int main () {
    int n,m,i,j,x,y,t,q,type;
    long long int res=0;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d%d%d",&x,&y,&t);
        x--; y--;
        a[x].push_back(y); wht[x].push_back(t);
        a[y].push_back(x); wht[y].push_back(t);
        orig[i]=i;
        }
    for (i=0; i<n; i++) {
        st=i; dfs(st,-1);
        for (j=0; j<n; j++) {
            if (i==j) continue;
            if (ans[i][j].size()!=2) continue;
            if (ans[i][j][0]<ans[i][j][1]) swap(ans[i][j][0],ans[i][j][1]);
            }
        }
    scanf("%d",&q);
    for (i=0; i<q; i++) {
        scanf("%d%d%d",&type,&x,&y);
        x--; y--;
        if (type==1) res+=2*ans[orig[x]][orig[y]][0]+ans[orig[x]][orig[y]][1];
        else swap(orig[x],orig[y]);
        }
    cout << res ;
    cout << endl ;
    return 0;
}
