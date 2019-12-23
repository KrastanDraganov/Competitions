/* TASK: Towers
   Author: Rusko Shikov
   SOLUTION: O(N!*N^2)    
*/ 
#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

const int nmax=100001;
int L[nmax+1];
int p[nmax+1];
int Lp[nmax+1];

int n;

void input()
{   int i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d", &L[i]);
        
    }
}

void buildLp()
{
    int i,j;
    bool found;
    for (i=1;i<=n;i++)
      Lp[i]=0;
    for (i=1;i<n;i++)
    {
       found=false; 
       for (j=i+1;(j<=n)&&!found;j++)
         if (p[i]<p[j])
         {
             Lp[j]++;
             found=true;
         }  
    }
}

bool LpEqualL()
{
    int i;
    bool equal;
    equal=true;
    for (i=1;(i<=n) && equal;i++)
      equal=equal&&(Lp[i]==L[i]);
    return equal;  
}

int main()
{  
    int i;
    input();
    for (i=1;i<=n;i++)
      p[i]=i;
    do
    {
        buildLp();
        if (LpEqualL())
        {
            for (i=1;i<=n;i++)
              printf("%d\n",p[i]);
            break;  
        }
    }
    while(next_permutation(p+1,p+n+1));  
    return 0;
}
