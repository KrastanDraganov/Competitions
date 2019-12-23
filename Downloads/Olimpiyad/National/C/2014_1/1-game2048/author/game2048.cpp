#include <iostream>
#include <cstdio>
using namespace std;
int n=3, ans, sum, moves;
int a[4][4];
void copy_table(int A[4][4], int B[4][4])
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            B[i][j]=A[i][j];
}
int dir(int way)
{
    int x = 1, y = 0, s = 0, l = 1;
    if(way%2) x=-x, l=3;
    if(way>2) swap(x, y);
    for(int t = 1; t<=3; t++)
        {
            int i = t, j = l;
            if(way<3) swap(i,j);
            int i1 = i+x, j1 = j+y, i2 = i1+x, j2 = j1+y;
            if(a[i2][j2]==a[i1][j1])
            {
                a[i2][j2]*=2;
                a[i1][j1]=0;
                s+=a[i2][j2];
                if(a[i2][j2]) a[i1][j1]=a[i][j];
                else a[i2][j2]=a[i][j];
                a[i][j]=0;
            }
            else if(a[i][j]==a[i1][j1])
            {
                a[i1][j1]*=2;
                s+=a[i1][j1];
                a[i][j]=0;
                if(!a[i2][j2]) swap(a[i2][j2],a[i1][j1]);
            }
            else if(a[i1][j1]==0)
            {
                if(a[i][j]==a[i2][j2])
                {
                    a[i2][j2]*=2;
                    s+=a[i2][j2];
                    a[i][j]=0;
                }
                else swap(a[i][j],a[i1][j1]);
            }
            else if(a[i2][j2]==0)
            {
                a[i2][j2]=a[i1][j1];
                a[i1][j1]=a[i][j];
                a[i][j]=0;
            }
        }
    return s;
}
void rec(int cnt)
{
    int b[4][4], old = 0;
    if(ans < sum || (ans==sum && moves > cnt)) { ans = sum; moves = cnt;}
    if(cnt == 10) return;
    copy_table(a,b);
    for(int i = 1; i <= 4; i++)
    {
        old = dir(i);
        sum+=old;
        rec(cnt+1);
        sum-=old;
        copy_table(b,a);
    }
}
int main() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    rec(0);
    printf("%d %d\n", ans, moves);
    return 0;
}
