#include <iostream>
using namespace std;

using ULL = unsigned long long;

ULL mulmod(ULL a, ULL n, ULL m)
{ if(n==0) return 0;
  if(n==1) return a%m;

  ULL k = n/2;
  ULL r = mulmod(a,k,m);
  r = 2*r%m;
  if(n%2==1) r = (r+a)%m;
  return r;
}

int main()
{ ULL a, n, m;
  cin >> a >> n >> m;
  cout << mulmod(a,n,m) << endl;

  return 0;
}
