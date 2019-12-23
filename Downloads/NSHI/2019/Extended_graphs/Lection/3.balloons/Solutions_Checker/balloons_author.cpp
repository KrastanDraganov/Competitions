#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

//using std::pair;
//using std::make_pair;

const int MAXN = 1 << 12;  //  4000
const int MAXM = 1 << 16;  // 64000
const int MAXK = 8;

const int BITS = 4;
const unsigned MASK = (1 << BITS) - 1;

struct edge_t {
  int to;
  int dist;
  int next;
  edge_t() {}
  edge_t(int _to, int _dist, int _next)
    : to(_to), dist(_dist), next(_next) {}
};

int N, M, C, K;
int colors[MAXN];
int gr[MAXN];
edge_t edge[MAXM * 2];
unsigned CLEAN_MASK;

int path_len;
int path[MAXN];

struct node_t {
  int to;
  unsigned prev;
  int dist;
  node_t() {}
  node_t(int _to, unsigned _prev, int _dist)
    : to(_to), prev(_prev), dist(_dist) {}
  node_t(const node_t &existing, const edge_t &e) {
    int new_color = colors[e.to];
    int crnt_color = colors[existing.to];

    to = e.to;
    prev = ((existing.prev << BITS) | crnt_color) | CLEAN_MASK;
    dist = existing.dist + e.dist;

    // printf("%x (%d %d) %x | %x\n",
    //     existing.prev, crnt_color, new_color, prev, CLEAN_MASK);

    // Now we check if the new color is ok. If it isn't set to = -1.

    // printf("    nc %d -> %d\n", e.to, new_color);

    if (K <= 0) return;  // no constraint at all
    if (new_color == crnt_color) {
      // printf("  BAD 1\n");
      to = -1;
      return;
    }

    for (int i = K - 2; i >= 0; --i) {
      int col = (existing.prev >> (i * BITS)) & MASK;
      // printf("    x %d\n", col);
      if (col == new_color) {
        // printf("  BAD 2\n");
        to = -1;
        return;
      }
    }
  }

  unsigned long long toHash() const {
    return (((unsigned long long) to) << 32ull) | ((unsigned long long) prev);
  }
};

typedef std::priority_queue<node_t> queue_t;
// typedef std::unordered_set<unsigned long long> set_t;
typedef std::map<unsigned long long, int> best_dist_t;
typedef std::map<unsigned long long, node_t> parent_t;
typedef best_dist_t::iterator best_dist_it_t;
// typedef set_t::iterator set_it_t;

const bool operator < (const node_t &a, const node_t &b) {
  return a.dist > b.dist;
}

void restore_path(node_t end, parent_t &parent) {
  int i = 0;
  node_t crnt = end;
  while (crnt.to != -1) {
    path[i++] = crnt.to;
    crnt = parent[crnt.toHash()];
  }
  path_len = i;
  std::reverse(path, path + i);
}

int dijkstra(int start, int end) {
  queue_t queue;
  // set_t popped;
  best_dist_t best_dist;
  parent_t parent;

  {
    node_t s(start, (~0u) | CLEAN_MASK, 0);
    best_dist.insert(make_pair(s.toHash(), s.dist));
    parent.insert(make_pair(s.toHash(), node_t(-1, 0, -1)));
    queue.push(s);
  }

  while (!queue.empty()) {
    node_t crnt = queue.top(); queue.pop();
    // printf("> %d (%x) %d | from %d (%x)\n", crnt.to, crnt.prev, crnt.dist, \
        parent[crnt.toHash()].to, parent[crnt.toHash()].prev);
    if (crnt.to == end) {
      restore_path(crnt, parent);
      return crnt.dist;
    }
    best_dist_it_t it;
    // if ((it = popped.find(crnt.toHash())) != popped.end()) {
    //   // printf("FUCK THAT\n");
    //   // got a worse solution
    //   continue;
    // }
    if (best_dist.find(crnt.toHash())->second != crnt.dist) {
      // popped should take care
      continue;
    }
    // popped.insert(crnt.toHash());

    for (int i = gr[crnt.to]; i != -1; i = edge[i].next) {
      // printf("  %d %d\n", edge[i].to, edge[i].dist);
      node_t next(crnt, edge[i]);
      if (next.to == -1) {
        // printf("  F %d (%x)\n", edge[i].to, next.prev);
        // This guy is invalid
        continue;
      }
      if ((it = best_dist.find(next.toHash())) == best_dist.end() ||
          it->second > next.dist) {
        best_dist[next.toHash()] = next.dist;
        parent[next.toHash()] = crnt;

        queue.push(next);
      }
      // if (popped.find(next.toHash()) != popped.end()) {
      //   // already processed
      //   continue;
      // }
      // printf("  p %d %x %d %Lx\n", next.to, next.prev, next.dist, next.toHash());
    }
  }

  return -1;
}

// void print_graph() {
//   for (int i = 0; i < N; ++i) {
//     printf("%d ->", i);
//     for (int j = gr[i]; j != -1; j = edge[j].next) {
//       printf(" %d %d", edge[j].to, edge[j].dist);
//     }
//     puts("");
//   }
// }

int main() {
  int start, end;
  scanf("%d %d", &N, &M);
  scanf("%d %d", &C, &K);
  scanf("%d %d", &start, &end);
  -- start; -- end;

  CLEAN_MASK = ~0u ^ ((1 << (BITS * (K - 1))) - 1);

  for (int i = 0; i < N; ++i) {
    scanf("%d", colors + i);
    -- colors[i];
  }

  memset(gr, -1, N * sizeof(int));
  int ep = 0;
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    -- a; -- b;

    edge[ep] = edge_t(b, c, gr[a]);
    gr[a] = ep ++;

    edge[ep] = edge_t(b, c, gr[a]);
    gr[a] = ep ++;
  }

  printf("%d\n", dijkstra(start, end));
  printf("%d\n", path_len);
  printf("%d", path[0] + 1);
  for (int i = 1; i < path_len; ++i) {
    printf(" %d", path[i] + 1);
  }
  printf("\n");

  return 0;
}
