// Not solved - time limit, 20 points

#include<iostream>
#include<array>

#define endl '\n'

using namespace std;

const int MAXN = 2e4 + 3, MAXL = 20, INF = 1e9 + 3;
int points[MAXN][2], log2[MAXN];

// 0 - min number, 1 - max number
array<int, 2> rmq[MAXN][MAXL];

void calc_rmq(int n) {
    for (int i = 2; i <= n; ++i) {
        log2[i] = log2[i/2] + 1;
    }

    for (int i = 0; i < n; ++i) {
        rmq[i][0][0] = rmq[i][0][1] = points[i][1];
    }

    for (int len = 1; len <= log2[n]; ++len) {
        for(int i = 0; i + (1 << len) - 1 < n; ++i) {
            int j = i + (1 << (len - 1));
            rmq[i][len][0] = min(rmq[i][len-1][0], rmq[j][len-1][0]);
            rmq[i][len][1] = max(rmq[i][len-1][1], rmq[j][len-1][1]);
        }
    }
}

array<int, 2> query(int l, int r) {
    if (l > r) {
        return {INF, -1};
    }
    int interval = log2[r-l+1];

    array<int, 2> res;
    res[0] = min(rmq[l][interval][0], rmq[r-(1<<interval)+1][interval][0]);
    res[1] = max(rmq[l][interval][1], rmq[r-(1<<interval)+1][interval][1]);

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    calc_rmq(n);

    int res = INF;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            int width = points[r][0] - points[l][0];

            array<int, 2> left_interval = query(0, l - 1);
            array<int, 2> right_interval = query(r + 1, n - 1);

            int miny = min(left_interval[0], right_interval[0]);
            int maxy = max(left_interval[1], right_interval[1]);

            if (miny == INF) {
                miny = maxy = 0;
            }

            res = min(res, width + maxy - miny);
        }
    }

    cout << res << endl;
return 0;
}
