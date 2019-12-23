#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct path { int v,mask;
              int dist;
              int prevv,prevmask; };
int conf[1001],dist[1001][10001],used[1001][10001],prev1[1001],prevv[1001][10001][2];
vector <int> a[1001],wht[1001];
priority_queue <path> vers;
bool operator< (path ex1, path ex2) {
     if (ex1.dist>ex2.dist) return true;
     return false;
}
stack <int> ans;
int main () {
    int n,m,c,k,st,fin,i,x,y,t,curv,mask,p,pow;
    path ex;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&c,&k);
    scanf("%d%d",&st,&fin);
    st--; fin--;
    pow=1;
    for (i=1; i<=k; i++) {
        pow*=(c+1);
        }
    for (i=0; i<n; i++) {
        scanf("%d",&conf[i]);
        }
    for (i=0; i<m; i++) {
        scanf("%d%d%d",&x,&y,&t);
        x--; y--;
        a[x].push_back(y); wht[x].push_back(t);
        a[y].push_back(x); wht[y].push_back(t);
        }
    dist[st][conf[st]]=0; used[st][conf[st]]=1; prevv[st][conf[st]][0]=-1;
    curv=st; mask=conf[st];
    for (;;) {
        if (curv==fin) break;
        ex.prevv=curv; ex.prevmask=mask;
        ex.dist=dist[curv][mask];
        memset(prev1,0,sizeof(prev1));
        p=mask;
        for (;;) {
            if (p==0) break;
            prev1[p%(c+1)]=1;
            p/=(c+1);
            } //cout << mask << endl ;
        mask*=(c+1); mask%=pow;
        for (i=0; i<a[curv].size(); i++) {
            if (prev1[conf[a[curv][i]]]==0) {
               ex.v=a[curv][i]; ex.mask=mask+conf[a[curv][i]];
               if (used[ex.v][ex.mask]==0) {
                  ex.dist+=wht[curv][i];
                  vers.push(ex);
                  ex.dist-=wht[curv][i];
                  }
               }
            }
        curv=-1;
        for (;;) {
            if (vers.empty()==1) break;
            ex=vers.top(); vers.pop();
            if (used[ex.v][ex.mask]==0) {
               curv=ex.v; mask=ex.mask;
               dist[ex.v][ex.mask]=ex.dist;
               used[ex.v][ex.mask]=1;
               prevv[ex.v][ex.mask][0]=ex.prevv;
               prevv[ex.v][ex.mask][1]=ex.prevmask;
               break;
               }
            }
        if (curv==-1) break;
        }
    cout << dist[curv][mask] << endl ;
    for (;;) {
        ans.push(curv);
        if (prevv[curv][mask][0]==-1) break;
        ex.v=prevv[curv][mask][0]; ex.mask=prevv[curv][mask][1];
        curv=ex.v; mask=ex.mask;
        }
    cout << ans.size() << endl ;
    for (i=0; ; i++) {
        if (ans.empty()==1) break;
        if (i!=0) cout << " ";
        cout << ans.top()+1 ;
        ans.pop();
        }
    cout << endl ;
    return 0;
}
