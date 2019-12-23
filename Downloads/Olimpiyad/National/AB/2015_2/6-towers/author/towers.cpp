/* TASK: Towers
   Author: Rusko Shikov
   SOLUTION: O(N*logN), Stack, Sort    
*/ 
#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

const int nmax=1000000;
const int dmax=1200000;

int L[nmax+1];
int p[nmax+1];

int n;

struct hm 
{
    long long v;
    int index;
    bool operator<(const hm& x) const
    {
      return (v < x.v);
    }
};

hm pom[nmax+1];

void input()
{   int i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d", &L[i]);
        
    }
   
}

int main()
{
    int i,j,c;
    stack<int> st;
    input();
    pom[1].v=0;
    pom[1].index=1;
    
    st.push(1);
    for(i=2;i<=n;i++)
      if (L[i]==0)
      {
        pom[i].v=pom[i-1].v-dmax;
        pom[i].index = i;
        st.push(i);
      }
      else
      {
        for(j=1;j<=L[i];j++)
        {
          c=st.top();
          st.pop();    
        }
        pom[i].v=pom[c].v+1;
        pom[i].index=i;
        st.push(i);
      }
    sort(pom+1,pom+n+1);
    for (i=1;i<=n;i++)
      p[pom[i].index]=i;  
    
    for (i=1;i<=n;i++)
        printf("%d\n", p[i]);
}