#include<iostream>
using namespace std;
long long N;
long M;
long pow2(long long p)
{if (!p) return 1;
 if (p&1) return (pow2(p-1)<<1)%M;
 long long d=pow2(p>>1);
 return (d*d)%M;
}
long R()
{long long s=3*pow2(N+1);
 N%=M;
 long long t=(N*N+3*N+5)%M;
 if (s<t) s+=M;
 return (s-t)%M;
}
int main()
{cin>>N>>M;
 cout<<R()<<endl;
 return 0;
}
