/*
ID: espr1t
LANG: C++
TASK: Next
KEYWORDS: Easy, Bruteforce, Iteration, Slow
*/

#include <cstdio>
const long long INF = 9876543210LL;

long long nextNumber(long long start) {
    for (long long candidate = start + 1; candidate <= INF; candidate++) {
        int mask = (1 << (candidate % 10));
        for (int tmp = candidate / 10; tmp > 0; tmp /= 10) {
            if (mask & (1 << (tmp % 10))) {
                mask = -1;
                break;
            }
            mask |= (1 << (tmp % 10));
        }
        if (mask != -1)
            return candidate;
    }
    return -1;
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
