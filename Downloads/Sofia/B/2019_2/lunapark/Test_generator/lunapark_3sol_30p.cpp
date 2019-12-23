#include<iostream>
#include<stdio.h>
#include<vector>
#include<time.h>
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
int third_solution (char* name1, char* name2) {
    FILE *in=fopen(name1,"r"),*out=fopen(name2,"w");
    int n,m,i,j,x,y,t,q,type;
    double beg1,end1;
    cout << "third solution: reading the graph started\n";
    beg1=clock();
    fscanf(in,"%d",&n);
    for (i=0; i<n; i++) {
        fscanf(in,"%d%d%d",&x,&y,&t);
        x--; y--;
        a[x].push_back(y); wht[x].push_back(t);
        a[y].push_back(x); wht[y].push_back(t);
        orig[i]=i;
        }
    cout << "third solution: reading the graph ended\n";
    cout << "third solution: precomputing all the answers started\n";
    for (i=0; i<n; i++) {
        st=i; dfs(st,-1);
        for (j=0; j<n; j++) {
            if (i==j) continue;
            if (ans[i][j].size()!=2) continue;
            if (ans[i][j][0]>ans[i][j][1]) swap(ans[i][j][0],ans[i][j][1]);
            }
        }
    cout << "third solution: precomputing all the answers ended\n";
    cout << "third solution: reading and printing queries started\n";
    fscanf(in,"%d",&q);
    for (i=0; i<q; i++) {
        fscanf(in,"%d%d%d",&type,&x,&y);
        x--; y--;
        if (type==1) fprintf(out,"%d %d\n",ans[orig[x]][orig[y]][0],ans[orig[x]][orig[y]][1]);
        else swap(orig[x],orig[y]);
        }
    end1=clock();
    cout << "third solution: reading and printing queries ended\n";
    cout << "third solution: ended!!!\n";
    printf("third solution working time: %.2lf s\n",(end1-beg1)/CLOCKS_PER_SEC);
    fclose(in); fclose(out);
    return 0;
}
