#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <limits.h>

using namespace std;

const int nmax=1000000;
int p[nmax+1];
int L[nmax+1];

int n,m;

int main()
{
   int i, u, v, x; 
   scanf("%d %d",&n,&m);
   
   for (i=1;i<=n;i++)
     p[i]=i;
   srand(time(0));  
   for (i=1;i<=m;i++)
   {
       u=rand()*rand()%n+1;
       v=rand()*rand()%n+1;
       if (u != v)
       {
           x=p[u];p[u]=p[v];p[v]=x;
       }
   }
   
  stack<int> st;
    
  st.push( INT_MAX );
  
  for ( i = 1; i <= n; i++ )
  {
    L[i]=0;  
    while ( st.top() < p[i] )
    {
      st.pop();
      L[i]++;      
    }
    st.push( p[i] );
  }
  
  printf ("%d\n",n);
  
  for (i=1;i<=n;i++)
    printf("%d\n",L[i]);
}