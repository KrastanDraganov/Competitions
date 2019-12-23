
#include <stdio.h>

#define MAXE 100000
#define MAXV 10000
using namespace std;
struct edge
{
  int t, len;
  struct edge *next;
} edges[2 * MAXE];

struct vertex
{
  int dist;
  struct edge *nbrs;
} verts[MAXV];

void add_nbr (int v, int t, int len, struct edge *e){
  e->t = t;
  e->len = len;
  e->next = verts[v].nbrs;
  verts[v].nbrs = e;
}

void dijkstra (int v, int dist, int k, int *distk){
  struct edge *to;
  if(dist >= verts[v].dist)return;
  if(verts[v].dist == k)(*distk)--;
  verts[v].dist = dist;
  for(to = verts[v].nbrs; to; to = to->next)
     dijkstra(to->t, dist + to->len, k, distk);
}

int main(void){
  int n, m, a, k, i, distk;

  scanf ("%d%d%d%d", &n, &m, &a, &k);

  distk = n;
  for(i = 0; i < n; i++){
	  verts[i].dist = k;
	  verts[i].nbrs = NULL;
  }
  for(i = 0; i < m; i++){
	  int v1, v2, len;
	  scanf ("%d%d%d", &v1, &v2, &len);
	  add_nbr (v1 - 1, v2 - 1, len, edges + 2 * i);
	  add_nbr (v2 - 1, v1 - 1, len, edges + 2 * i + 1);
  }
  for(i = 0; i < a; i++){
	  int v;
	  scanf ("%d", &v);
	  if (distk > 0)
	    dijkstra (v - 1, 0, k, &distk);

  }
  printf ("%d\n", distk);
 // printf("\n");
  return 0;
}
