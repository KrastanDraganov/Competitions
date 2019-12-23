/*
ID: espr1t
TASK: DivisorSequences
KEYWORDS: Medium, Dynamic Programming
*/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 1024;
const int MOD = 1000000009;

int n, k;
int dyn[MAX][MAX];
vector <int> neighbors[MAX];

int recurse(int idx, int last) {
    if (idx >= n)
        return 1;
    if (dyn[idx][last] != -1)
        return dyn[idx][last];

    int ans = 0;
    for (int i = 0; i < (int)neighbors[last].size(); i++) {
        ans += recurse(idx + 1, neighbors[last][i]);
        if (ans >= MOD) ans -= MOD;
    }
    return dyn[idx][last] = ans;
}

int main(void) {
    FILE* in = stdin; FILE* out = stdout;
//    in = fopen("DivisorSequences.in", "rt");
//    out = fopen("DivisorSequences.out", "wt");

    fscanf(in, "%d %d", &n, &k);
    
    for (int num = 1; num <= k; num++)
        for (int i = 1; i <= k; i++)
            if (num % i == 0 || i % num == 0)
                neighbors[num].push_back(i);

    memset(dyn, -1, sizeof(dyn));
    fprintf(out, "%d\n", recurse(0, 1));

    return 0;
}
