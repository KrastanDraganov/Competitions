#include <cstdio>
#define MAXN 205

int a[MAXN][MAXN][MAXN];

int main() {
  int z, y, x, L, M, N, x1, y1, z1, x2, y2, z2;
  char c;
  scanf("%d %d",&N, &M);
  for (z=1; z<=N; z++) for (y=1; y<=N; y++) for (x=1; x<=N; x++){
    scanf(" %c",&c);
    a[z][y][x]=(c=='G'?1:0);
    a[z][y][x] += a[z-1][y][x] - a[z-1][y-1][x] + a[z-1][y-1][x-1] - a[z-1][y][x-1]
                + a[z][y][x-1] - a[z][y-1][x-1] + a[z][y-1][x];
  }

  while (M-- > 0) {
    scanf("%d %d %d %d %d %d", &z1, &y1, &x1, &z2, &y2, &x2);
    printf("%d\n",a[z2][y2][x2] - a[z2][y1-1][x2] + a[z2][y1-1][x1-1] - a[z2][y2][x1-1] +
                a[z1-1][y2][x1-1] - a[z1-1][y1-1][x1-1] + a[z1-1][y1-1][x2] - a[z1-1][y2][x2] );
  }
  return 0;
}

