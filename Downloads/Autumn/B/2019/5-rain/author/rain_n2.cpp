#include<iostream>
using namespace std;


const int MM=10111222;

int n,nc;
int a[MM],b[MM], e1[MM], e2[MM];

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


void roof()
{
  e1[0]=0;
  e2[n-1]=0;

  int k1=findmaxFL(0,n-1);
  int k2=findmaxLR(0,n-1);



  if(k1<k2)
  {
    e2[k1]=a[k1];
    e1[k2]=a[k2];
  }



    int k01=k1;
    while(1)
    {
      int k=findmaxFL(0,k01-1);
      if(k==-1) break;
      e1[k01]=a[k];
      e2[k]=a[k];
      k01=k;
    }

    int k02=k2;
    while(1)
    {
      int k=findmaxLR(k02+1,n-1);
      if(k==-1) break;
      e2[k02]=a[k];
      e1[k]=a[k];
      k02=k;
    }


  //compute max volume:

  long long int v=0;
  int h=e2[0];
  for(int i=1;i<n;i++)
  {
     v=v+h;
     if(e2[i]!=0) h=e2[i];
  }

  long long int vmax=v;

  int ch=0;

  int kh=-1;
  if(k1==k2) kh=k1;



/**/
  if(b[0]!=0)
  if(kh!=0)
  {
   ch++; /*cout << 0 << " ";*/
  }
  else
  {
    if(a[0]-b[0]<e2[0] && e2[0] <= a[0]) {ch++; /*cout << 0 << " ";*/}
  }
/**/


  for(int i=1;i<n-1;i++)
  if(b[i]!=0)
  {
    if(i==kh)
    {
     if(e1[i]!=e2[i])
     {
     int em=max(e1[kh],e2[kh]);
     if(a[i]-b[i]<em) { ch++; /* cout << i << " ";*/}
     }
    }
  else
    {
    if(e1[i]!=e2[i])
     { ch++; /*cout << i << " ";*/}
    }
  }



/**/
  if(b[n-1]!=0)
  if(kh!=n-1)
  {
    ch++; //cout << n-1 << " ";
  }
  else
  {
    if(a[n-1] - b[n-1] < e1[n-1] && e1[n-1] <= a[n-1]) {ch++; /*cout << n-1 << " ";*/}
  }

  cout << ch << " " << vmax << endl;



}


int main()
{

  ios_base::sync_with_stdio(0);

  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];

  cin >> nc;

  for(int j=1;j<=nc;j++)
  {
    int v,w; cin >> v >> w;
    b[v]=w;
  }


  for(int i=0;i < n; i++) a[i]=a[i]+b[i];

  roof();


}




