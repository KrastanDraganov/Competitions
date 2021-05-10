#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define endl '\n'

using namespace std;

const int64_t MAXS = 4e12;

struct Point {
    int64_t x, y;

    bool operator<(const Point& comp) {
        if (x == comp.x) {
            return y < comp.y;
        }

        return x < comp.x;
    }
};

const int MAXN = 5e4 + 3;
vector<int64_t> tree[4 * MAXN];

void build_tree(int ind, int tl, int tr, vector<Point>& centers) {
    if (tl == tr) {
        tree[ind] = {centers[tl].y};
        return;
    }

    int mid = (tl + tr) / 2;
    build_tree(2 * ind, tl, mid, centers);
    build_tree(2 * ind + 1, mid + 1, tr, centers);

    tree[ind].reserve(tr - tl + 1);
    merge(tree[2 * ind].begin(), tree[2 * ind].end(),
          tree[2 * ind + 1].begin(), tree[2 * ind + 1].end(),
          back_inserter(tree[ind]));
}

bool tree_query(int ind, int tl, int tr, int l, int r, int64_t left_limit, int64_t right_limit) {
    if (l > r or l > tr or r < tl) {
        return 0;
    }

    if (l == tl and r == tr) {
        auto it = lower_bound(tree[ind].begin(), tree[ind].end(), left_limit);
        return it != tree[ind].end() and *it <= right_limit;
    }

    int mid = (tl + tr) / 2;
    if (r <= mid) {
        return tree_query(2 * ind, tl, mid, l, r, left_limit, right_limit);
    } else if (l > mid) {
        return tree_query(2 * ind + 1, mid + 1, tr, l, r, left_limit, right_limit);
    } else {
        return tree_query(2 * ind, tl, mid, l, mid, left_limit, right_limit)
             | tree_query(2 * ind + 1, mid + 1, tr, mid + 1, r, left_limit, right_limit);
    }
}

bool cmp_by_x_lower(const Point& point, const int64_t& target) {
    return point.x < target;
}

bool cmp_by_x_upper(const int64_t& target, const Point& point) {
    return point.x > target;
}

bool is_point_covered(int64_t side, Point& curr_point, vector<Point>& centers, int n) {
    int64_t l_x = curr_point.x - (side / 2);
    int64_t r_x = curr_point.x + (side / 2);

    int64_t l_y = curr_point.y - (side / 2);
    int64_t r_y = curr_point.y + (side / 2);

    int limit_l_x = lower_bound(centers.begin(), centers.end(), l_x, cmp_by_x_lower) - centers.begin();
    if (limit_l_x == n) {
        return false;
    }

    int limit_r_x = upper_bound(centers.begin(), centers.end(), r_x, cmp_by_x_upper) - centers.begin();
    --limit_r_x;

    return tree_query(1, 0, n - 1, limit_l_x, limit_r_x, l_y, r_y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Point> centers(n);
    for (int i = 0; i < n; ++i) {
        cin >> centers[i].x >> centers[i].y;
    }
    sort(centers.begin(), centers.end());

    build_tree(1, 0, n - 1, centers);

    vector<Point> points(m);
    for (int i = 0; i < m; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    vector<int64_t> min_side_length(m);
    for (int i = 0; i < m; ++i) {
        int64_t l = 2, r = MAXS;
        while (l <= r) {
            int64_t mid = (l + r) / 2;

            if (is_point_covered(mid, points[i], centers, n)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        min_side_length[i] = r + 1;
    }

    int q;
    cin >> q;

    sort(min_side_length.begin(), min_side_length.end());
    for (int i = 0; i < q; ++i) {
        int64_t side;
        cin >> side;

        int res = upper_bound(min_side_length.begin(), min_side_length.end(), side) - min_side_length.begin();
        cout << res << " ";
    }
    cout << endl;
return 0;
}
