#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector <int> a[100000],num[100000];
int reb[300000][3],b[100000],in[100000],rem[300000];
int dfs (int vr) {
    in[vr]--;
    if ((b[vr]==0)||(in[vr]>0)) return 0;
    int i;
    b[vr]=0;
    for (i=0; i<a[vr].size(); i++) {
        if (rem[num[vr][i]]==0) {
           dfs(a[vr][i]);
           rem[num[vr][i]]=1;
           }
        }
}
int main () {
    int n,m,q,x,y,i,reb1,reb2,br=0;
    scanf("%d%d",&n,&m);
    for (i=0; i<m; i++) {
        scanf("%d%d",&reb[i][0],&reb[i][1]);
        a[reb[i][0]].push_back(reb[i][1]);
        num[reb[i][0]].push_back(i);
        in[reb[i][1]]++;
        rem[i]=0;
        }
    for (i=1; i<=n; i++) {
        b[i]=1;
        }
    cin >> q ;
    for (i=0; i<q; i++) {
        scanf("%d%d",&x,&y);
        if (x==2) printf("%d\n",b[y]);
        else if (rem[y-1]==0) dfs(reb[y-1][1]), rem[y-1]=1;
        }
    return 0;
}
