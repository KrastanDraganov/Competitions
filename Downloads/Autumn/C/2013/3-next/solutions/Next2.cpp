/*
ID: espr1t
LANG: C++
TASK: Next
KEYWORDS: Easy, Brute-force, Recursion, Slow
*/

#include <cstdio>
#include <algorithm>

const long long INF = 9876543210LL;

long long nnRecurse(long long num, int mask, long long limit) {
    if (num > limit)
        return num;
    long long ans = INF;
    for (int dig = !num; dig < 10; dig++) if (!(mask & (1 << dig)))
        ans = std::min(ans, nnRecurse(num * 10 + dig, mask | (1 << dig), limit));
    return ans;
}

long long nextNumber(long long start) {
    return start >= INF ? -1 : nnRecurse(0, 0, start);
}

int main(void) {
//    freopen("Next.in", "rt", stdin);
//    freopen("Next.out", "wt", stdout);
    int numTests;
    fscanf(stdin, "%d", &numTests);
    for (int test = 0; test < numTests; test++) {
        long long num;
        fscanf(stdin, "%lld", &num);
        fprintf(stdout, "%lld\n", nextNumber(num));
    }
    return 0;
}
