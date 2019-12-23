/* TASK: Towers
   Author: Rusko Shikov
   SOLUTION: O(N!*N)    
*/ 
#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;

const int nmax=100001;
int L[nmax+1];
int p[nmax+1];
int Lp[nmax+1];
int st[nmax+1];
int ukst;

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
  
  int i;  
  st[1]=INT_MAX; ukst=1;
  
  for ( i = 1; i <= n; i++ )
  {
    Lp[i]=0;  
    while ( st[ukst] < p[i] )
    {
      ukst--;
      Lp[i]++;      
    }
    ukst++; st[ukst]=p[i];
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
