/*
AUTHOR: espr1t
TASK: Towers
SOLUTION: O(N*logN), Medium, Stack, Index Tree
*/

#include <cstdio>
#include <stack>
#include <utility>
#include <cassert>
#include <algorithm>

using namespace std;
FILE* in; FILE* out;

const int INF = 1000000001;
const int MAX = 1310720;
const int TREE = 2621440;

int n;
int a[MAX];
int tree[TREE];

void update(int idx1, int idx2, int val) {
    if (idx2 < idx1)
        return;

    idx1 += (TREE >> 1), idx2 += (TREE >> 1);
    if (idx1 == idx2) {
        tree[idx1] += val;
        return;
    }
    tree[idx1] += val; bool flag1 = !(idx1 & 1); idx1 >>= 1;
    tree[idx2] += val; bool flag2 =  (idx2 & 1); idx2 >>= 1;
    while (idx1 != idx2) {
        if (flag1) tree[(idx1 << 1) + 1] += val; flag1 = !(idx1 & 1); idx1 >>= 1;
        if (flag2) tree[(idx2 << 1) + 0] += val; flag2 =  (idx2 & 1); idx2 >>= 1;
    }
}

int query(int idx) {
    int ret = 0;
    for (idx = idx + (TREE >> 1); idx > 0; idx >>= 1)
        ret += tree[idx];
    return ret;
}

void solve() {
    stack < pair <int, int> > s;
    s.push(make_pair(INF, -1));
    for (int i = 0; i < n; i++) {
        int num = n - i;
        for (int c = 0; c < a[i]; c++) {
            num = s.top().first, s.pop();
        }
        update(s.top().second + 1, i - 1, -1);
        update(i, i, num);
        s.push(make_pair(num, i));
    }
    for (int i = 0; i < n; i++)
        fprintf(out, "%d%c", query(i), i + 1 == n ? '\n' : ' ');
}

int main(void) {
    in = stdin; out = stdout;
//    in = fopen("towers.in", "rt"); out = fopen("towers.out", "wt");
    
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(in, "%d", &a[i]);
    
    solve();
    return 0;
}
