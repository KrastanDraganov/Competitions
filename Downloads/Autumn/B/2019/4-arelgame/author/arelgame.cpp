#include <iostream>
#include <algorithm>
using namespace std;
long long A,B,d,A1,B1;
long long gcd(long long a,long long b)
{long long c;
 if (a<b){c=a;a=b;b=c;}
 do
 {c=a%b;
  if (!c) return b;
  a=b;
  b=c;
 }while (true);
}
int main()
{cin>>A>>B;
 if (A==B){cout<<0<<endl;return 0;}
 if (A>B) swap(A,B);
 d=gcd(A,B);
 if (d==1){cout<<0<<endl;return 0;}
 A1=A/d;B1=B/d;
 if (A<B1){cout<<0<<endl; return 0;}
 cout<<min(A/B1,B1/A1-!(B1%A1))<<endl;
 return 0;
}
