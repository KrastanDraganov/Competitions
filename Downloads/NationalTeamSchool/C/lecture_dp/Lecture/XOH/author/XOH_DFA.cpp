#include<iostream>
using namespace std;
int M,N;
unsigned long w[2][9]={{1,0,0,0,0,0,0,0,0},
                       {1,0,0,0,0,0,0,0,0}
                      };
void update(int p)
{int q=p^1;
 w[p][1]=(w[q][5]+w[q][6]+2*w[q][1])%M;
 w[p][2]=(w[q][1]+w[q][2])%M;
 w[p][3]=(w[q][7]+2*w[q][3])%M;
 w[p][4]=(w[q][8]+2*w[q][4])%M;
 w[p][5]=(w[q][0]+w[q][5])%M;
 w[p][6]=(w[q][0]+w[q][6])%M;
 w[p][7]=(w[q][5]+w[q][7])%M;
 w[p][8]=(w[q][6]+w[q][8])%M;
}
int main()
{cin>>N>>M;
 int p=0;
 for (int i=0;i<N;i++)
 {p=p^1;
  update(p);
 }
 unsigned long s=0;
 for (int i=0;i<9;i++) s=(s+w[p][i])%M;
 cout<<s<<endl;
 return 0;
}
