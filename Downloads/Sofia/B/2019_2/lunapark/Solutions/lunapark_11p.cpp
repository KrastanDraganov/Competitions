#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
vector <int> a[200001],wht[200001],ans;
int used[200001],cur,fin;
int dfs (int vr, int max1) {
    if (fin==vr) {
       ans.push_back(max1);
       return 0;
       }
    if (used[vr]==1) return 0;
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
        }
    scanf("%d",&q);
    for (i=0; i<q; i++) {
        scanf("%d%d%d",&type,&x,&y);
        x--; y--; fin=y;
        ans.clear(); dfs(x,-1);
        if (ans[0]<ans[1]) swap(ans[0],ans[1]);
        res+=2*ans[0]+ans[1];
        }
    cout << res ;
    cout << endl ;
    return 0;
}
