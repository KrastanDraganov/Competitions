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

void solution()
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


  int k=0;
  while(k<k1)
  {
    int j=k+1;
    while(a[j]<=a[k]) j++;
    e2[k]=a[k];
    e1[j]=a[k];
    k=j;
  }

  k=n-1;
  while(k>k2)
  {
    int j=k-1;
    while(a[j]<=a[k]) j--;
    e1[k]=a[k];
    e2[j]=a[k];
    k=j;
  }


   //compute max volume:

  long long int vmax=0;
  int h=e2[0];
  for(int i=1;i<n;i++)
  {
     vmax += h;
     if(e2[i]!=0) h=e2[i];
  }

  // which to remove:

  int ch=0;

  int kh=-1;
  if(k1==k2) kh=k1;


/**/
  if(b[0]!=0)
  if(kh!=0) ch++;
  else
  {
    if(a[0]-b[0]<e2[0] && e2[0] <= a[0]) ch++;
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
      if(a[i]-b[i]<em) ch++;
     }
    }
    else
    {
     if(e1[i]!=e2[i]) ch++;
    }
  }

/**/
  if(b[n-1]!=0)
  if(kh!=n-1) ch++;
  else
  {
    if(a[n-1] - b[n-1] < e1[n-1] && e1[n-1] <= a[n-1]) ch++;
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

  solution();


}




