#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<iomanip>
#include<cstring>
using namespace std;



const int MM=1009999;

int n,nc;
int a[MM],b[MM];


int findmaxFL(int i1, int i2)
{
  int m=0;int j=-1;
  for(int i=i1;i<=i2;i++)
  {
    if(a[i]>m){m=a[i];j=i;}
  }
  return j;
}


int findmaxLR(int i1, int i2)
{
  int m=0;int j=-1;
  for(int i=i1;i<=i2;i++)
  {
    if(a[i]>=m){m=a[i];j=i;}
  }
  return j;

}


int compute()
{
  int k=findmaxFL(0,n-1);
  int k2=k;
  int k0=k;
  int s=0;

  while(1)
  {
    int k=findmaxFL(0,k2-1);
    if(k==-1) break;
    s += (k2-k)*a[k];
    k2=k;
  }

  int k1=k0;
  while(1)
  {
    int k=findmaxFL(k1+1,n-1);
    if(k==-1) break;
    s += (k-k1)*a[k];
    k1=k;
  }
  return s;
}

int chn=0;
int minchn=999999999;
int t[MM],t0[MM];

int smax=0;

void go(int i)
{
  if(i==n)
    {int s=compute();
     if(s==smax) if(chn < minchn)
     { minchn=chn;
       for(int j=0;j<=chn;j++) t0[j]=t[j];
     }
     return;
    }
  if(b[i]==0) go(i+1);
  else
  {
    a[i] += b[i]; chn++; t[chn]=i;
    go(i+1);
    a[i] -= b[i]; chn--;
    go(i+1);
  }
}


int main()
{

  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];

  cin >> nc;

  for(int j=1;j<=nc;j++)
  {
    int v,w; cin >> v >> w;
    b[v]=w;
  }

  for(int i=0;i < n; i++) a[i]=a[i]+b[i];

  smax=compute();

  for(int i=0;i < n; i++) a[i]=a[i]-b[i];


  go(0);

  cout << minchn << " " << smax << endl;

}





