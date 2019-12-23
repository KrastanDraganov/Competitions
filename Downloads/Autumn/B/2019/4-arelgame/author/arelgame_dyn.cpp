#include<iostream>
#include<algorithm>
using namespace std;
int const N=60000;
int A,B;
char state[(N>>1)*(N-1)];
int C=0;
long long ind(long long a,long long b)
{if (a>b)swap(a,b);
 return a*(N+1)+b;
}
int play(int player,int a,int b)
{int mask=state[ind(a,b)];
 if (mask>=0) return player ^ mask;
 if (a*A!=b*B && a*B!=b*A) {state[ind(a,b)]=0;return player;}
 for (int i=0;i<=a;i++)
  for (int j=0;j<=b;j++)
   if ((i||j) && i*A!=j*B && i*B!=j*A)
   {if (play(player^3,a-i,b-j)==player)
    {state[ind(a,b)]=0;
     return player;
    }
   }
 state[ind(a,b)]=3;
 return player^3;
}
int main()
{cin>>A>>B;
 state[0]=0;
 for (long long i=0;i<=min(A,B);i++)
  for (long long j=0;j<=max(A,B);j++)
   state[ind(i,j)]=-1;
 for (long long i=0;i<=A;i++)
  for (long long j=0;j<=B;j++)if ((j||i) && A*i!=B*j && A*j!=B*i)
  {int p=play(2,A-i,B-j);
   if (p==1) C++;
  }
 cout<<C<<endl;
 return 0;
}
