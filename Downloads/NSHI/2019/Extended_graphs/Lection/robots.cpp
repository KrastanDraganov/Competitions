#include<iostream>
#include<queue>
using namespace std;
int tab[50][50];
int drow[2][2] = { { -1, +1 },
                   { +0, +0 } };
int dcol[2][2] = { { +0, +0 },
                   { -1, +1 } };
int dep[10000000];
int main () {
    int n,m,i,j,row[2],col[2],newrow[2],newcol[2],pos,newpos;
    queue <int> bfs;
    cin >> n >> m ;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            cin >> tab[i][j] ;
            }
        }
    for (i=0; i<2; i++) {
        cin >> row[i] >> col[i] ;
        row[i]--; col[i]--;
        }
    pos=(row[0]*50+col[0])*2500+row[1]*50+col[1];
    dep[pos]=1;
    bfs.push(pos);
    while (!bfs.empty()) {
        pos=bfs.front();
        row[0]=(pos/2500)/50; col[0]=(pos/2500)%50;
        row[1]=(pos%2500)/50; col[1]=(pos%2500)%50;
        if ((row[0]==row[1])&&(col[0]==col[1])) {
           cout << dep[pos]-1 ;
           break;
           }
        for (i=0; i<2; i++) {
            newrow[0]=row[0]+drow[tab[row[1]][col[1]]][i];
            newcol[0]=col[0]+dcol[tab[row[1]][col[1]]][i];
            if ((newrow[0]<0)||(newrow[0]>=n)||(newcol[0]<0)||(newcol[0]>=m)) continue;
            if (tab[newrow[0]][newcol[0]]==-1) continue;
            for (j=0; j<2; j++) {
                newrow[1]=row[1]+drow[tab[row[0]][col[0]]][j];
                newcol[1]=col[1]+dcol[tab[row[0]][col[0]]][j];
                if ((newrow[1]<0)||(newrow[1]>=n)||(newcol[1]<0)||(newcol[1]>=m)) continue;
                if (tab[newrow[1]][newcol[1]]==-1) continue;
                newpos=(newrow[0]*50+newcol[0])*2500+newrow[1]*50+newcol[1];
                if (dep[newpos]!=0) continue;
                dep[newpos]=dep[pos]+1;
                bfs.push(newpos);
                }
            }
        bfs.pop();
        }
    cout << endl ;
    return 0;
}
