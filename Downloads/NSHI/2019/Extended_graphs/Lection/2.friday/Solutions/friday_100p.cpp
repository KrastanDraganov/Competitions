#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
struct reb { int vr;
             int wht; };
struct ver { int num;
             int mask;
             int way; };
vector <reb> a[100];
int mind[100],masks[5000][20],st[20],dist[100];
bool b[50][4096][13];
string s;
int main () {
    int i,j,h,k,t,n,m,x,br;
    reb p;
    ver top,p1;
    cin >> t ;
    for (i=1; i<=t; i++) {
        cin >> n >> m ;
        for (j=0; j<n; j++) {
            mind[j]=1000000;
            a[j].clear();
            dist[j]=1000000;
            }
        mind[0]=0;
        for (j=1; j<=m; j++) {
            cin >> x >> p.vr >> p.wht ;
            p.vr--;
            a[x-1].push_back(p);
            }
        cin >> s ;
        if (s=="False") {
           for (j=1; j<=n-1; j++) {
               for (h=0; h<n; h++) {
                   for (k=0; k<a[h].size(); k++) {
                       if (mind[a[h][k].vr]>mind[h]+a[h][k].wht) mind[a[h][k].vr]=mind[h]+a[h][k].wht;
                       }
                   }
               }
           if (mind[n-1]==1000000) cout << -1 ;
           else cout << mind[n-1] ;
           }
        else { memset(b,0,sizeof(b));
               stack <ver> c;
               for (j=1; j<4096; j++) {
                   for (h=1; h<=12; h++) {
                       masks[j][h]=masks[j-1][h];
                       }
                   for (h=12; ; h--) {
                       masks[j][h]=(masks[j][h]+1)%2;
                       if (masks[j][h]!=0) break;
                       }
                   }
               st[0]=1;
               for (j=1; j<=15; j++) {
                   st[j]=st[j-1]*2;
                   }
               top.num=0;
               top.mask=0;
               top.way=0;
               br=0;
               for (;;) {
                   b[top.num][top.mask][top.way%13]=1;
                   dist[top.num]=min(dist[top.num],top.way);
                   if (top.num!=n-1) {
                      for (j=0; j<a[top.num].size(); j++) {
                          if ((masks[top.mask][(top.way+a[top.num][j].wht)%13]==0)&&((top.way+a[top.num][j].wht)%13!=0)) {
                             p1.num=a[top.num][j].vr;
                             p1.mask=top.mask+st[12-((top.way+a[top.num][j].wht)%13)];
                             p1.way=top.way+a[top.num][j].wht;
                             if (b[p1.num][p1.mask][p1.way%13]==0) c.push(p1);
                             }
                          }
                      }
                   for (;;) {
                       if (c.empty()==1) break;
                       p1=c.top();
                       if (b[p1.num][p1.mask][p1.way%13]==0) break;
                       c.pop();
                       }
                   if (c.empty()==1) break;
                   top=c.top();
                   }
               if (dist[n-1]==1000000) cout << -1 ;
               else cout << dist[n-1] ;
               }
        cout << endl ;
        }
    //system ("PAUSE");
    return 0;
}
