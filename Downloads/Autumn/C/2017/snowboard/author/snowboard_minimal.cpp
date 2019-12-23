#include <iostream>
unsigned long long A[2][200][400];
int n,m,p,cr,pr=1,i,j,k,down;
int main () {
  std::cin >> n >> m >> p;
  if (p<m) goto print;
  for (i=0; i<m; i++) A[cr][i][i]=1; /// init table
  for (i=1; i<n; i++) /// fill table
    for (cr^=1, pr^=1, A[cr][0][i]=1, A[cr][0][i-1]=0, j=1; j<m; A[cr][j++][k]=0)
      for (k=i+j, down=(i>j?i:j) ; k>=down; k--)
        A[cr][j][k]=(A[cr][j-1][k-1]+A[pr][j-1][k-1]+A[pr][j][k-1])%0x4000000000000000LL;
print: std::cout << A[cr][m-1][p-1] << '\n';
  return 0;
}
