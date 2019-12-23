#include <stdio.h>
#define DO(P) if (i+P<n) A[i+P]=(A[i+P]+A[i])%MOD;\
              else s=(s+A[i])%MOD;
int A[8000]={1}, m,n,p,q,i,j,k,s;
const int MOD = 1<<14;
int main(){
  scanf(" %d %d %d %d", &m, &n, &p, &q);
  for (n-=m+p, k=p-q; i<n; i++) {
    DO(p)
    DO(k)
  }
  printf("%d\n",(s?s:1));
  return 0;
}
