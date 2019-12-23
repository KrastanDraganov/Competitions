/*
ID: espr1t
TASK: HiddenWords
KEYWORDS: Easy, DFS
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 52;

int n, m, k;
char board[MAX][MAX];
char word[MAX]; int len;

bool vis[MAX][MAX][MAX];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool recurse(int row, int col, int idx) {
    vis[row][col][idx] = true;
    if (idx >= len) return true;
    for (int i = 0; i < 4; i++) {
        int nrow = row + dir[i][0]; if (nrow < 0 || nrow >= n) continue;
        int ncol = col + dir[i][1]; if (ncol < 0 || ncol >= m) continue;
        if (board[nrow][ncol] == word[idx] && !vis[nrow][ncol][idx + 1])
            if (recurse(nrow, ncol, idx + 1)) return true;
    }
    return false;
}

bool eval() {
    memset(vis, 0, sizeof(vis));
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (board[row][col] == word[0])
                if (recurse(row, col, 1)) return true;
        }
    }
    return false;
}

int main(void) {
    FILE* in = stdin; FILE* out = stdout;
    //in = fopen("HiddenWords.in", "rt");
    //out = fopen("HiddenWords.out", "wt");

    fscanf(in, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        fscanf(in, "%s", board[i]);
    fscanf(in, "%d", &k);
    //cout << k <<endl;
    for (int i = 0; i < k; i++) {
        fscanf(in, "%s", word);
        len = (int)strlen(word);
        fprintf(out, "%s\n", eval() ? "Yes" : "No");
    }
    return 0;
}
