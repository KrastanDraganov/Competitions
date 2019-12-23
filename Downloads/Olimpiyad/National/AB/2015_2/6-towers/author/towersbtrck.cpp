/* TASK: Towers
   Author: Anton Shikov
   SOLUTION: Backtracking
*/
#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

const int nmax=1000000;

int L[nmax+1];
int p[nmax+1];
int used[nmax+1];
int sol[nmax+1];

int n;
bool found = false;

void input()
{   int i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d", &L[i]);

    }

}

void track(int pos)
{
    int i, j, currentL, MaxH;

    for (i = 1; i <= n; i++)
        if (!used[i])
        {
            used[i] = true;
            sol[pos] = i;
            currentL = 0;
            MaxH = 0;
            for (j = pos - 1; j > 0; j--)
                if ((sol[j] > MaxH) && (sol[j] < sol[pos])) // kula na pozicia j se pokriva ot kula na pozicia i
                {
                    currentL++;
                    MaxH = sol[j];
                }

             if (currentL == L[pos])   // ok sme s tova, koeto sme slojili
             {                 
               if (pos == n)
               {
                 found = true;
                 for (j=1;j<=n;j++)
                   printf("%d\n", sol[j]);
                 return;
               }
               else
                 track(pos+1);
             }
             if (found) return;
             used[i] = false;
        }
}

int main()
{
    int i;

    input();

    for (i=1; i <= n; i++)
        used[i] = false;

    track(1);

}
