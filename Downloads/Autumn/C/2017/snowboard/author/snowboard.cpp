#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull A[2][200][400];
int n,m,p;
const ull MOD = ((ull)(-1)>>2) + 1;  /// MOD=0x4000000000000000LL;

int main () {
  int cr=0, prev=1, i, j, k, down;
  cin >> n >> m >> p;
  if (p<m) goto print;
  /// init table
  for (i=0; i<m; i++) A[cr][i][i]=1;
  /// fill table
  for (i=1; i<n; i++)
    for (cr^=1, prev^=1, A[cr][0][i]=1, A[cr][0][i-1]=0, j=1; j<m; A[cr][j++][k]=0)
      for (k=i+j, down=(i>j?i:j) ; k>=down; k--)
        A[cr][j][k]=(A[cr][j-1][k-1]+A[prev][j-1][k-1]+A[prev][j][k-1])%MOD;

  print:  cout << A[cr][m-1][p-1] << endl;
  return 0;
}
