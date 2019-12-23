/*
ID: espr1t
TASK: Persistence
KEYWORDS: Easy, Bruteforce
*/

#include <cstdio>
FILE* in = stdin; FILE* out = stdout;

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

int main(void) {
    // in = fopen("Persistence.in", "rt");

    int p;
    fscanf(in, "%d", &p);

    long long num = 0;
    while (findPersistence(num) < p)
        num++;
    fprintf(out, "%lld\n", num);

    return 0;
}
