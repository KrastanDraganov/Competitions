/*
ID: espr1t
TASK: HiddenWords
KEYWORDS: Easy, BFS
*/

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 52;

struct State {
    int row, col, idx;
};

int n, m, k;
char a[MAX][MAX];
char word[MAX]; int len;

queue <State> q;
bool vis[MAX][MAX][MAX];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool eval() {
    State cur, nxt;
    while (!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));

    nxt.idx = 1;
    for (nxt.row = 0; nxt.row < n; nxt.row++) {
        for (nxt.col = 0; nxt.col < m; nxt.col++) {
            if (a[nxt.row][nxt.col] == word[0]) {
                if (len == 1) return true;
                q.push(nxt);
                vis[nxt.row][nxt.col][nxt.idx] = true;
            }
        }
    }
    while (!q.empty()) {
        cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            nxt.row = cur.row + dir[i][0]; if (nxt.row < 0 || nxt.row >= n) continue;
            nxt.col = cur.col + dir[i][1]; if (nxt.col < 0 || nxt.col >= m) continue;
            if (word[cur.idx] == a[nxt.row][nxt.col]) {
                nxt.idx = cur.idx + 1;
                if (nxt.idx == len) return true;
                if (!vis[nxt.row][nxt.col][nxt.idx]) {
                    q.push(nxt);
                    vis[nxt.row][nxt.col][nxt.idx] = true;
                }
            }
        }
    }
    return false;
}

int main(void) {
    FILE* in = stdin; FILE* out = stdout;
    //in = fopen("HiddenWords.in", "rt"); out = fopen("HiddenWords.out", "wt");
    
    fscanf(in, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        fscanf(in, "%s", a[i]);
    fscanf(in, "%d", &k);
    for (int i = 0; i < k; i++) {
        fscanf(in, "%s", word);
        len = (int)strlen(word);
        fprintf(out, "%s\n", eval() ? "Yes" : "No");
    }
    return 0;
}
