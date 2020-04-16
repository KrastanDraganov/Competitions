#include<cstdio>
#include<deque>
using namespace std;

int N, L;
char S[int(1e7) + 2];

long long ans = 0;

// if step==+1: then iterate [x, x+1, ..., end-1]
// if step==-1: then iterate [x, x-1, ..., end+1]
void solve(int x, int end, int step) {
  deque<int> D;

  for(; ; x+=step) {
    // crop dist to L
    while (!D.empty() && step * (x - D.back()) > L)
      D.pop_back();

    // add traverses from to x
    ans += D.size();

    if (x == end)
      break;

    if ((S[x] == '-') == (step == +1))
      // add the current point if descending follows 
      D.push_front(x);
    else
      if (!D.empty())
        // delete the last (descending) point if ascending follows
        D.pop_front();
  }
}

int main() {
  scanf("%d%d", &N, &L);
  scanf("%s", S);

  solve(0, N, +1);    // left -> right
  solve(N-1, -1, -1); // right -> left

  printf("%lld\n", ans);

  return 0;
}

