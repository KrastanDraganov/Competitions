#include<iostream>
using namespace std;
long long N;
long M;
int main()
{long D2=4,D1=2,R=1;
 cin>>N>>M;
 for (long long i=1;i<=N;i++)
 {R=(R+D1)%M;
  D1=(D1+D2)%M;
  D2=((D2<<1)+2)%M;
 }
 cout<<R<<endl;
 return 0;
}
