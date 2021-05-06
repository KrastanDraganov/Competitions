// Not solved - wrong answer, 0 points

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define endl '\n'

using namespace std;

const int64_t MAXS = 1e12;

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

void build_tree(int ind, int tl, int tr, vector<Point>& points) {
    if (tl == tr) {
        tree[ind] = {points[tl].y};
        return;
    }

    int mid = (tl + tr) / 2;
    build_tree(2 * ind, tl, mid, points);
    build_tree(2 * ind + 1, mid + 1, tr, points);

    tree[ind].reserve((int) (tree[2 * ind].size() + tree[2 * ind + 1].size()));
    merge(tree[2 * ind].begin(), tree[2 * ind].end(),
          tree[2 * ind + 1].begin(), tree[2 * ind + 1].end(),
          tree[ind].begin());
}

int tree_query(int ind, int tl, int tr, int l, int r, int64_t left_limit, int64_t right_limit) {
    if (l > r or l > tr or r < tl) {
        return 0;
    }

    if (l == tl and r == tr) {
        auto it1 = lower_bound(tree[ind].begin(), tree[ind].end(), left_limit);
        auto it2 = lower_bound(tree[ind].begin(), tree[ind].end(), right_limit);

        return it2 - it1 + 1;
    }

    int mid = (tl + tr) / 2;
    if (r <= mid) {
        return tree_query(2 * ind, tl, mid, l, r, left_limit, right_limit);
    } else if (l > mid) {
        return tree_query(2 * ind + 1, mid + 1, tr, l, r, left_limit, right_limit);
    } else {
        return tree_query(2 * ind, tl, mid, l, mid, left_limit, right_limit)
             + tree_query(2 * ind + 1, mid + 1, tr, mid + 1, r, left_limit, right_limit);
    }
}

int find_left_limit_x(int64_t side, Point& center, vector<Point>& points, int m) {
    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (2 * abs(center.x - points[mid].x) <= side) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return r;
}

int find_right_limit_x(int64_t side, Point& center, vector<Point>& points, int m) {
    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (2 * abs(center.x - points[mid].x) <= side) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l;
}

bool cmp_by_x(const Point& point, const int64_t& target) {
    return point.x < target;
}

bool is_point_covered(int64_t side, Point& center, vector<Point>& points, int m) {
    // int l_x = find_left_limit_x(side, center, points, m);
    // int r_x = find_right_limit_x(side, center, points, m);

    int64_t l_x = center.x - (side / 2);
    int64_t r_x = center.x + (side / 2);
    
    int64_t l_y = center.y - (side / 2);
    int64_t r_y = center.y + (side / 2);

    int limit_l_x = lower_bound(points.begin(), points.end(), l_x, cmp_by_x) - points.begin();
    int limit_r_x = lower_bound(points.begin(), points.end(), r_x, cmp_by_x) - points.begin();

    return tree_query(1, 0, m - 1, limit_l_x, limit_r_x, l_y, r_y);
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

    vector<Point> points(m);
    for (int i = 0; i < m; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());

    build_tree(1, 0, m - 1, points);

    vector<int64_t> min_side_length(n);
    for (int i = 0; i < n; ++i) {
        int64_t l = 2, r = MAXS;
        while (l <= r) {
            int64_t mid = (l + r) / 2;

            if (is_point_covered(mid, centers[i], points, m)) {
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

        auto it = lower_bound(min_side_length.begin(), min_side_length.end(), side);
        cout << min_side_length.end() - it << " ";
    }
    cout << endl;
return 0;
}