//Author: Emil Kelevedjiev

#include<iostream>
#include<algorithm>
using namespace std;

const int N=100002;
int n;

const int d=53;

int a[d], a0[d];

int u[N][4];

void read()
{
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    string s; cin >> s;
    int m=s.size();
    char c;
    int p[4]={0,0,0,0};
    int j=1;
    for(int k=1;k<=3;k++)
    {
      if(j>=m) break;
      c=s[j]; j++; p[k]=(int)(c-'0');
      if(j>=m) break;
      c=s[j]; j++;
      if(c=='S') continue;
      p[k]=10*p[k]+(int)(c-'0');
      if(j>=m) break;
      c=s[j]; j++;
    }
    for(int k=1;k<=3;k++)
     u[i][k]=p[k];
    a[p[1]]++;
    a0[p[1]]++;

  }
}

bool alg_1()
{
  //cout << "a";
  int nn=0;
  for(int i=1;i<d;i++)
    nn=nn+a[i];

  //cout << "nn=" << nn << endl;

  for(int i=1;i<d;i++)
  {
    if(a[i]>(nn-a[i]))
     {
       cout << "S"<<i<<" "<<a0[i]<< endl;
       return true;
     }
  }

  return false;

}


int mar[d];

bool alg_3()
{

 for(int i=0;i<d;i++) mar[i]=0;

  int m1=999999999;
  for(int i=1;i<d;i++)
    if(a[i]!=0)
    if(a[i]<m1) m1=a[i];

 for(int i=1;i<d;i++)
    if(a[i]!=0)
     if(a[i]!=m1) return false;

  for(int i=1;i<d;i++)
    if(a[i]==m1) mar[i]=1;

   int nnz=0;
   for(int i=1;i<d;i++)
    if(mar[i]!=0) nnz++;

   if(nnz==1) return false;

   bool ff=false;
   bool fff=false;
   for(int i=1;i<d;i++)
    if(mar[i]!=0)
     {
      fff=true;
      if(ff) cout << " ";
      cout << "S"<<i;
      ff=true;
     }

   if(fff) cout << endl;
   return true;
}


void do_alg_2()
{

  for(int i=0;i<d;i++) mar[i]=0;
  int m1=999999999;
  for(int i=1;i<d;i++)
    if(a[i]!=0)
    if(a[i]<m1) m1=a[i];
  for(int i=1;i<d;i++)
    if(a[i]==m1) mar[i]=1;

  for(int j=1;j<=n;j++)
  {
    if(mar[u[j][3]]==1) u[j][3]=0;
    if(mar[u[j][2]]==1)
    {
      u[j][2]=u[j][3];
      u[j][3]=0;
    }
    if(mar[u[j][1]]==1)
    {
      u[j][1]=u[j][2];
      u[j][2]=u[j][3];
      u[j][3]=0;
    }
  }

  for(int i=1;i<d;i++) a[i]=0;
  for(int j=1;j<=n;j++) a[u[j][1]]++;

}

int main()
{
  read();
  while(1)
  {
   if(alg_1()) return 0;
   if(alg_3()) return 0;
   do_alg_2();
  }
}
