#include<iostream>
#include<cstring>
using namespace std;
long Count=0;
char s[1000000];
bool check(const char *s)
{const char *p=s;
 p=strchr(s,'0');
 if (p) {p=strchr(p+1,'1');
         if (p) {p=strchr(p+1,'2');
                 if (p) return false;
                }
        }
 p=strchr(s,'2');
 if (p) {p=strchr(p+1,'1');
         if (p) {p=strchr(p+1,'0');
                 if (p) return false;
                }
        }
 return true;
}
void Proc(long long N,long M,char *s)
{s[N]=0;
 if (check(s))
 {Count++;
  if (Count==M) Count=0;
 }
}
void make(long long N,long M,long long k,char *s)
{if (k==N){Proc(N,M,s);return;}
 for (char c='0';c<='2';c++)
 {s[k]=c;
  make(N,M,k+1,s);
 }
}
void makeWords(long long N,long M,char *s)
{Count=0;
 *s=0;
 make(N,M,0,s);
}
int main()
{long long N;
 long M;
 cin>>N>>M;
 makeWords(N,M,s);
 cout<<Count<<endl;
 return 0;
}
