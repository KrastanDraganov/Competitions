/*
ID: espr1t
TASK: Persistence
KEYWORDS: Testgen
*/

#include <cstdio>

int main(void) {
    long long answers[12] = {0, 10, 25, 39, 77, 679, 6788, 68889, 2677889, 26888999, 3778888999LL, 277777788888899LL};
    int tests[21] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11};

    for (int test = 0; test < 21; test++) {
        char inpFile[32], solFile[32];
        sprintf(inpFile, "Persistence.%02d.in", test);
        sprintf(solFile, "Persistence.%02d.sol", test);

        FILE* inp = fopen(inpFile, "wt");
        fprintf(inp, "%d\n", tests[test]);
        fclose(inp);

        FILE* sol = fopen(solFile, "wt");
        fprintf(sol, "%lld\n", answers[tests[test]]);
        fclose(sol);
    }

    return 0;
}
