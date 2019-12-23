#include <iostream>
using namespace std;
long long M,N;
int p;
long sumDig(long long a,int radix)
{long s=0;
 while (a){s+=a%radix;a/=radix;}
 return s;   
}
long sumDig(long long prevN, long prevSum,int radix)
{while (prevN%radix==p-1)
 {prevSum-=p-1;
  prevN/=radix;
 }
 return prevSum+1;
}
int main()
{ long long S;
  long s;
  cin>>M>>N>>p;
  s=S=sumDig(M,p);
  for (long long i=M+1;i<M+N;i++) {s=sumDig(i-1,s,p);S+=s;}
  cout<<S<<endl;
  return 0;
}
