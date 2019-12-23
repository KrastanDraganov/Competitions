#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
bool tab[21][15];
int dp[21][15][16385][2],st[15],m,n,mod=1000000031LL;
int zero (int num, int bit) {
    num|=st[bit];
    num^=st[bit];
    return num;
}
int one (int num, int bit) {
    num|=st[bit];
    return num;
}
bool check (int num, int bit) {
     return (num&st[bit]);
}
int rec (int row, int col, int mask, int cur) {
    int mask1,sb=0;
    if ((col==m)&&(row==n-1)) return 1;
    if (col==m) return rec(row+1,0,mask,0);
    if (dp[row][col][mask][cur]!=-1) return dp[row][col][mask][cur];
    if ((tab[row][col]==1)||(check(mask,col)==1)) {
       if (cur==0) mask1=zero(mask,col);
       else mask1=one(mask,col);
       dp[row][col][mask][cur]=rec(row,col+1,mask1,0);
       return dp[row][col][mask][cur];
       }

    // --
    if ((col!=m-1)&&(tab[row][col+1]==0)&&(check(mask,col+1)==0)) {
       if (cur==0) mask1=zero(mask,col);
       else mask1=one(mask,col);
       mask1=zero(mask1,col+1);
       sb+=rec(row,col+2,mask1,0);
       }

    /* --
       -  */
    if ((row!=n-1)&&(col!=m-1)&&(tab[row][col+1]==0)&&(tab[row+1][col]==0)&&(check(mask,col+1)==0)&&(cur==0)) {
       mask1=one(mask,col);
       mask1=zero(mask1,col+1);
       sb+=rec(row,col+2,mask1,0);
       sb%=mod;
       }
    /* --
        - */
    if ((row!=n-1)&&(col!=m-1)&&(tab[row][col+1]==0)&&(tab[row+1][col+1]==0)&&(check(mask,col+1)==0)) {
       if (cur==0) mask1=zero(mask,col);
       else mask1=one(mask,col);
       mask1=one(mask1,col+1);
       sb+=rec(row,col+2,mask1,0);
       sb%=mod;
       }
    /* -
       -- */
    if ((row!=n-1)&&(col!=m-1)&&(tab[row+1][col]==0)&&(tab[row+1][col+1]==0)&&(cur==0)) {
       mask1=one(mask,col);
       sb+=rec(row,col+1,mask1,1);
       sb%=mod;
       }
    /*  -
       -- */
    if ((row!=n-1)&&(tab[row+1][col-1]==0)&&(tab[row+1][col]==0)&&(cur==0)&&(col!=0)&&(check(mask,col-1)==0)) {
       mask1=one(mask,col-1);
       mask1=one(mask1,col);
       sb+=rec(row,col+1,mask1,0);
       sb%=mod;
       }
    /* -
       -  */
    if ((row!=n-1)&&(tab[row+1][col]==0)&&(cur==0)) {
       mask1=one(mask,col);
       sb+=rec(row,col+1,mask1,0);
       sb%=mod;
       }
    dp[row][col][mask][cur]=sb;
    return sb;
}
int main () {
    int i,j,h;
    string a;
    /*freopen("test.in","r",stdin);
    freopen("test.sol","w",stdout);*/
    for (;;) {
        cin >> m >> n ;
        if ((m==0)&&(n==0)) break;
        getline(cin,a);
        for (i=0; i<n; i++) {
            getline(cin,a);
            for (j=0; j<m; j++) {
                if (a[j]=='.') tab[i][j]=0;
                else tab[i][j]=1;
                }
            }
        st[0]=1;
        for (i=1; i<=m; i++) {
            st[i]=2*st[i-1];
            }
        for (i=0; i<n; i++) {
            for (j=0; j<m; j++) {
                for (h=0; h<st[m]; h++) {
                    dp[i][j][h][0]=dp[i][j][h][1]=-1;
                    }
                }
            }
        cout << rec(0,0,0,0) << endl ;
        }
    return 0;
}
