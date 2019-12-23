#include <iostream>
using namespace std;

int a[21];

long long nf(int n)
{ long long r = 1;
  for(int i=2; i<=n; i++)
    r = r*i;
  return r;
}

int main()
{ int n;
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> a[i];

  long long t = 0;

  for(int p=1; p<=n; p++)
  { int k=0;
    for(int i=p+1; i<=n; i++)
      if(a[p]>a[i]) k++;
    t = t + k*nf(n-p);
  }
  t++;

  cout << t << endl;

  return 0;
}
