/*
ID: espr1t
TASK: Codes
KEYWORDS: Easy/Medium/Hard, Greedy, Bruteforce, DP, Hungarian
NOTES (for Group C):
  -- Not using bruteforce for small costs ~20 points
  -- just printing all words one after the other yields ~15 points
  -- printing all words one after the other (smartly) yields ~25 points
  -- using the greedy yields ~100 points
*/

#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10000;
const int LEN = 8;
const int BASE = 100000; // 10^(k-1)

int n, k;
char a[MAX][LEN];

bool used[MAX];
queue <int> q[LEN][BASE];

/*
    There are plenty of options how to proceed when the number of codes is
    relatively small. The contestants could choose between:
      -- backtrack: works fine up to 10 (optimal)
      -- next permutation: works fine up to 10 (optimal)
      -- dynamic programming: works fine up to 20 (optimal, complicated)
      -- hungarian algorithm: works fine up to 100-500 (very complicated)
*/
string solveForSmall() {
    string ans;
    // Find match between all pairs of codes
    int match[10][10];
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < n; c++) if (i != c) {
            match[i][c] = k - 1;
            while (match[i][c] > 0) {
                bool flag = true;
                for (int j = 0; j < match[i][c]; j++) {
                    if (a[c][j] != a[i][k - match[i][c] + j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) break;
                match[i][c]--;
            }
        }
    }
    int ord[10];
    for (int i = 0; i < n; i++)
        ord[i] = i;
    do {
        int len = k;
        for (int i = 1; i < n; i++)
            len += k - match[ord[i - 1]][ord[i]];
        if (ans == "" || len < (int)ans.length()) {
            ans = a[ord[0]];
            for (int i = 1; i < n; i++)
                for (int c = match[ord[i - 1]][ord[i]]; c < k; c++)
                    ans.push_back(a[ord[i]][c]);
        }
    } while (next_permutation(ord, ord + n));
    return ans;
}

/*
    For large inputs any good solution is not feasible, as it will require
    enormous amount of time and memory.
    We will use the following greedy strategy. Initially, we take any word for
    the start - it might as well be the first one. Then take a word, that is
    still not used (it might be covered already, but we will not care).
    The greedy part is that we will take the word, that starts with the longest
    prefix, that is also suffix of the answer so far. This way we are sparing
    several (up to k-1) characters.
    We implement that by having several queues that store all possible codes,
    which will match the last [match] digits and start with [num]. This way
    the transitions are quite fast - each word is expected at most 7 times
    (which is the maximal length of a code).
*/
string solveForLarge() {
    for (int i = 0; i < n; i++) {
        q[0][0].push(i);
        for (int match = 1, num = 0; match < k; match++) {
            num = num * 10 + a[i][match - 1] - '0';
            q[match][num].push(i);
        }
    }
    
    int lastUsed = 0;
    string ans = a[lastUsed]; used[lastUsed] = true;
    for (int i = 1; i < n; i++) {
        for (int match = k - 1; match >= 0; match--) {
            int num = 0;
            for (int c = k - match; c < k; c++)
                num = num * 10 + a[lastUsed][c] - '0';
            int idx = -1;
            while (!q[match][num].empty()) {
                idx = q[match][num].front(); q[match][num].pop();
                if (!used[idx])
                    break;
                idx = -1;
            }
            if (idx != -1) {
                for (int c = match; c < k; c++)
                    ans.push_back(a[idx][c]);
                used[idx] = true, lastUsed = idx;
                break;
            }
        }
    }
    return ans;
}

int main(void) {
    FILE* in = stdin; FILE* out = stdout;
//    in = fopen("Codes.in", "rt"); out = fopen("Codes.out", "wt");

    fscanf(in, "%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        fscanf(in, "%s", a[i]);

    if (n <= 10)
        fprintf(out, "%s\n", solveForSmall().c_str()); // Bruteforce for small
    else
        fprintf(out, "%s\n", solveForLarge().c_str()); // Greedy for large
    return 0;
}
