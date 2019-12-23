#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

const int N=100001;
const int M=-999999999;

int a[N], d1[N], d2[N];
int n;

int main()
{
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  
  d1[0]=a[0];
  d2[0]=a[0];
  
  d1[1]=a[0]+a[1];
  d1[2]=d1[1]+a[2];
  
  d2[1]=M;
  d2[2]=a[0]+a[2];
  
  for(int i=3;i<n;i++)
  {
    d1[i]=a[i]+max(d1[i-1], d2[i-1]);
    d2[i]=a[i]+d1[i-2];
  }
  
/*
  for(int i=0;i<n;i++) cout << setw(3) << a[i] << "  ";
  cout << endl;
  for(int i=0;i<n;i++) cout << setw(3) << d1[i] << "  ";
  cout << endl;
  for(int i=0;i<n;i++) cout << setw(3) << d2[i] << "  ";
  cout << endl;
*/
  int r=M;
  for(int i=0;i<n;i++) if(r<d1[i]) r=d1[i];
  for(int i=0;i<n;i++) if(r<d2[i]) r=d2[i];
  
  cout << r << endl;
  
    
}
