#include <iostream>
using namespace std;
long long M,N;
int p;
long long deg[64];

int f(int n)
{return (n*(n-1))>>1;
}
long long sigma(int n, int p)
{long long r=(p*(p-1))>>1;
 return r*n*deg[n-1];
}
int digCnt(long long A)
{int n=1;
 while (deg[n]<=A) n++;
 return n;   
}
long long S(long long A,int p)
{long long s=0;
 int d;
 for (int i=digCnt(A)-1;i>=0;i--)
 {d=A/deg[i];
  s+=d*sigma(i,p)+deg[i]*f(d);
  A%=deg[i];
  s+=d*(A+1);
 }
 return s;
}
long long Sigma(long long M, long long N, int p)
{
 return S(M+N-1,p)-S(M-1,p);
}
int main()
{ cin>>M>>N>>p;
  deg[0]=1;
  for (int i=1;deg[i-1]<M+N;i++) 
  {deg[i]=deg[i-1]*p;
   if (deg[i]<=0) break;
  }
  cout<<Sigma(M,N,p)<<endl;
  return 0;
}
