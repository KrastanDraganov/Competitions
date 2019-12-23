/*
ID: espr1t
TASK: Persistence
KEYWORDS: Easy, Bruteforce
*/

#include <cstdio>
#include <algorithm>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

const int MAX = 13;
const long long INF = 100000000000000001LL;

long long ans[MAX];

int findPersistence(long long num) {
    int ret = 0;
    while (num >= 10) {
        ret++;
        long long nxt = 1;
        for (; num > 0; num /= 10)
            nxt *= num % 10;
        num = nxt;
    }
    return ret;
}

void recurse(long long num) {
    if (num >= INF)
        return;
    int pers = findPersistence(num);
    ans[pers] = min(ans[pers], num);
    for (long long d = max(1LL, num % 10); d < 10; d++)
        recurse(num * 10 + d);
}

int main(void) {
    // in = fopen("Persistence.in", "rt");
    for (int i = 0; i < MAX; i++)
        ans[i] = INF;

    ans[0] = 0;
    ans[1] = 10;
    recurse(0);

    int p;
    fscanf(in, "%d", &p);
    fprintf(out, "%lld\n", ans[p]);

    return 0;
}
