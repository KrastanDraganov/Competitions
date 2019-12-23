#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
char matrix[1001][1001];
int ans[1001][1001];
int main () {
    int n,m,i,j,h,fl,fl1=0,side;
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) {
        scanf("%s",&matrix[i]);
        }
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            ans[i][j]=0;
            if ((matrix[i][j]!='0')&&(matrix[i][j]!='1')) continue;
            fl1=0;
            if (matrix[i][j]!='0') fl1++;
            for (side=1; ; side++) {
                if ((j+side>=m)||(i+side>=n)) break;
                if ((matrix[i][j+side]!='0')&&(matrix[i][j+side]!='-')&&(matrix[i][j+side]!='2')) break;
                if ((matrix[i+side][j]!='0')&&(matrix[i+side][j]!='|')&&(matrix[i+side][j]!='4')) break;
                fl=0;
                if (((matrix[i][j+side]!='0')&&(matrix[i][j+side]!='2'))||
                    ((matrix[i+side][j]!='0')&&(matrix[i+side][j]!='4'))||
                    ((matrix[i+side][j+side]!='0')&&(matrix[i+side][j+side]!='3'))) fl++;
                if ((matrix[i][j+side]!='0')||(matrix[i+side][j]!='0')) fl1++;
                if (fl1==0) continue;
                if ((side==1)&&(fl==0)) {
                   ans[i][j]=1;
                   break;
                   }
                for (h=j+1; h<=j+side-1; h++) {
                    if ((matrix[i+side][h]!='0')&&(matrix[i+side][h]!='-')) {
                       fl++;
                       break;
                       }
                    }
                for (h=i+1; h<=i+side-1; h++) {
                    if ((matrix[h][j+side]!='0')&&(matrix[h][j+side]!='|')) {
                       fl++;
                       break;
                       }
                    }
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
