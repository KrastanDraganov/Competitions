#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
char matrix[1001][1001];
int ans[1001][1001],cnt[6][2][1001][1001],ind[2][1001][1001];
char sign[6]={'1', '2', '3', '4', '-', '|'};
int main () {
    int n,m,i,j,h,fl,side;
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) {
        scanf("%s",&matrix[i]);
        }
    for (i=0; i<n; i++) {
        ind[0][i][m-1]=m;
        for (j=m-2; j>=0; j--) {
            ind[0][i][j]=ind[0][i][j+1];
            if (matrix[i][j]!='0') ind[0][i][j]=j;
            }
        }
    for (i=0; i<m; i++) {
        ind[1][n-1][i]=n;
        for (j=n-2; j>=0; j--) {
            ind[1][j][i]=ind[1][j+1][i];
            if (matrix[j][i]!='0') ind[1][j][i]=j;
            }
        }
    for (i=0; i<6; i++) {
        for (j=0; j<n; j++) {
            cnt[i][0][j][0]=0;
            for (h=0; h<m; h++) {
                cnt[i][0][j][h+1]=cnt[i][0][j][h];
                if (matrix[j][h]==sign[i]) cnt[i][0][j][h+1]++;
                }
            }
        for (j=0; j<m; j++) {
            cnt[i][1][0][j]=0;
            for (h=0; h<n; h++) {
                cnt[i][1][h+1][j]=cnt[i][1][h][j];
                if (matrix[h][j]==sign[i]) cnt[i][1][h+1][j]++;
                }
            }
        }
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            ans[i][j]=0;
            if ((matrix[i][j]!='0')&&(matrix[i][j]!='1')) continue;
            if ((ind[0][i][j]==m)&&(ind[1][i][j]==n)) continue;
            for (side=min(ind[0][i][j]-j,ind[1][i][j]-i); ; side++) {
                if (side==0) continue;
                //br++;
                if ((j+side>=m)||(i+side>=n)) break;
                if ((matrix[i][j+side]!='0')&&(matrix[i][j+side]!='-')&&(matrix[i][j+side]!='2')) break;
                if ((matrix[i+side][j]!='0')&&(matrix[i+side][j]!='|')&&(matrix[i+side][j]!='4')) break;
                fl=0;
                if (((matrix[i][j+side]!='0')&&(matrix[i][j+side]!='2'))||
                    ((matrix[i+side][j]!='0')&&(matrix[i+side][j]!='4'))||
                    ((matrix[i+side][j+side]!='0')&&(matrix[i+side][j+side]!='3'))) fl++;
                if ((side==1)&&(fl==0)) {
                   ans[i][j]=1;
                   break;
                   }
                for (h=0; h<4; h++) {
                    if ((cnt[h][1][i+side][j+side]-cnt[h][1][i+1][j+side]!=0)||
                        (cnt[h][0][i+side][j+side]-cnt[h][0][i+side][j+1]!=0)) {
                       fl++;
                       break;
                       }
                    }
                if ((cnt[4][1][i+side][j+side]-cnt[4][1][i+1][j+side]!=0)||
                    (cnt[5][0][i+side][j+side]-cnt[5][0][i+side][j+1]!=0)) fl++;
                if (fl==0) {
                   ans[i][j]=side;
                   break;
                   }
                if ((matrix[i][j+side]=='2')||(matrix[i+side][j]=='4')) break;
                }
            }
        }
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            if (ans[i][j]==0) continue;
            printf("%d %d %d\n",i+1,j+1,ans[i][j]);
            }
        }
    return 0;
}
