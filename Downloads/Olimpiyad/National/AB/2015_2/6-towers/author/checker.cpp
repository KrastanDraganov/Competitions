#include <cstdio>
#include <stack>
#include <limits.h>


using namespace std;

const int nmax=1000000;

int ncount[nmax+1];
int Larray[nmax+1];
int p[nmax+1];
int n;

int main(int argc, char * argv[]) {
  int i, v;
  //FILE *wsol;
  FILE *wout;
  FILE *win;

  win=fopen(argv[1],"r");
  //wsol=fopen(argv[3],"r");
  wout=fopen(argv[3],"r");

  if (win==NULL)
    {   printf("0\nCannot open in file\n");
        return 1;
    }
    if (wout==NULL)
    {   printf("0\nCannot open out file\n");
        return 1;
    }
    //if (wsol==NULL)
    //{   printf("0\nCannot open sol file\n");
      //  return 1;
    //}

  int x = fscanf(win,"%d",&n);
  for (i=1;i<=n;i++)
    int x = fscanf(win,"%d", &Larray[i]);
  for (i=1;i<=n;i++)
    ncount[i]=0;
  int m=0;
  int check;
  check=fscanf(wout,"%d",&v);
  if (check>0)
  {
      m++;
      p[m]=v;
      if ((p[m]>=1) && (p[m]<=n))
        ncount[p[m]]++;
      else
      {
        printf("%i\nWrong element (not between 1 and  %i) - %i\n", 0, n, p[m]);
        return 0;
      }
  }
  while (check>0)
  {
    check=fscanf(wout,"%d",&v);
    if (check>0)
    {
      m++;
      p[m]=v;
      if ((p[m]>=1) && (p[m]<=n))
        ncount[p[m]]++;
      else
      {
        printf("%i\nWrong element (not between 1 and  %i) - %i\n", 0, n, p[m]);
        return 0;
      }
    }

  }
  if (m!=n)
  {
     printf("%i\nWrong number of elements: expected %i, found %i\n", 0, n, m);
     return 0;
  }

  for (i=1;i<=n;i++)
  {
     if (ncount[i]==0)
     {
        printf("%i\nThis is not a permutation - number %i is missing\n",0,i);
        return 0;
     }
     if (ncount[i]>1)
     {
        printf("%i\nThis is not a permutation - number %i occurs more then once\n",0,i);
        return 0;
     }
  }

  stack<int> st;
  int L;

  st.push( INT_MAX );

  for ( i = 1; i <= n; i++ )
  {
    L=0;
    while ( st.top() < p[i] )
    {
      st.pop();
      L++;
    }
    st.push( p[i] );
    if (L!=Larray[i])
    {
      printf("%i\nWrong answer for tower %i - wrong number of covered towers: expected %i, found %i\n", 0, i, Larray[i], L);
      return 0;
    }
  }
  printf("%f\nAccepted\n", 1.0);

  return 0;

}


