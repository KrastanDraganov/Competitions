#include <iostream>
using namespace std;
long long M,N;
int p;
long sumDig(long long a,int radix)
{long s=0;
 while (a){s+=a%radix;a/=radix;}
 return s;   
}
int main()
{ long long S=0;
  cin>>M>>N>>p;
  for (long long i=M;i<M+N;i++) S+=sumDig(i,p);
  cout<<S<<endl;
  return 0;
}
