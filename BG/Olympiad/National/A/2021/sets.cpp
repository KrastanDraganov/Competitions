// Not solved - time limit, 75 points, subtask 6

#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN = 2e6 + 3, INF = 1e9;
int x[MAXN], y[MAXN];

const int MIN = 0, MAX = 1, MINMAX = 2;
int prefix[MAXN][2], suffix[MAXN][2];
int tree[4 * MAXN][3];

int get_value(int ind, int type) {
    if (type == MIN) {
        return x[ind] - suffix[ind][MIN];
    }

    if (type == MAX) {
        return x[ind] + suffix[ind][MAX];
    }

    return x[ind] + suffix[ind][MAX] - suffix[ind][MIN];
}

void build_trees(int ind, int tl, int tr) {
    if (tl == tr) {
        for (int type = 0; type < 3; ++type) {
            tree[ind][type] = get_value(tl, type);
        }
        return;
    }

    int mid = (tl + tr) / 2;
    build_trees(2 * ind, tl, mid);
    build_trees(2 * ind + 1, mid + 1, tr);

    for (int type = 0; type < 3; ++type) {
        tree[ind][type] = min(tree[2 * ind][type], tree[2 * ind + 1][type]);
    }
}

int query(int ind, int type, int tl, int tr, int l, int r) {
    if (l > tr or r < tl or l > r) {
        return INF;
    }

    if (l == tl and r == tr) {
        return tree[ind][type];
    }

    int mid = (tl + tr) / 2;
    return min(query(2 * ind, type, tl, mid, l, min(mid, r)),
               query(2 * ind + 1, type, mid + 1, tr, max(l, mid + 1), r));
}

int find_change_pos(int ind, int type, int n) {
    int l = ind, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (type == MIN) {
            if (suffix[mid][type] < prefix[ind][type]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            if (suffix[mid][type] > prefix[ind][type]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    return l - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int type = 0; type < 3; ++type) {
        for (int i = 0; i < 4 * MAXN; ++i) {
            tree[i][type] = INF;
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    prefix[0][MIN] = INF;
    prefix[0][MAX] = -INF;
    for (int i = 1; i < n; ++i) {
        prefix[i][MIN] = min(prefix[i - 1][MIN], y[i - 1]);
        prefix[i][MAX] = max(prefix[i - 1][MAX], y[i - 1]);
    }

    suffix[n - 1][MIN] = INF;
    suffix[n - 1][MAX] = -INF;
    for (int i = n - 2; i >= 0; --i) {
        suffix[i][MIN] = min(suffix[i + 1][MIN], y[i + 1]);
        suffix[i][MAX] = max(suffix[i + 1][MAX], y[i + 1]);
    }

    build_trees(1, 0, n - 2);

    int res = min(tree[1][MINMAX] - x[0], prefix[n - 1][MAX] - prefix[n - 1][MIN]);
    for (int i = 1; i < n - 1; ++i) {
        int change_pos_min = find_change_pos(i, MIN, n);
        int change_pos_max = find_change_pos(i, MAX, n);

        res = min(res, x[max(change_pos_max, change_pos_min) + 1] - x[i] + prefix[i][MAX] - prefix[i][MIN]);
        res = min(res, query(1, MIN, 0, n - 2, change_pos_max + 1, change_pos_min) - x[i] + prefix[i][MAX]);
        res = min(res, query(1, MAX, 0, n - 2, change_pos_min + 1, change_pos_max) - x[i] - prefix[i][MIN]);
        res = min(res, query(1, MINMAX, 0, n - 2, i, min(change_pos_max, change_pos_min)) - x[i]);
    }

    cout << res << endl;
return 0;
}