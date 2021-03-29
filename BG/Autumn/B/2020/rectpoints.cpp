#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

struct Point {
    int x, y;
    int lowest, highest;

    Point() {
        x = y = lowest = highest = -1;
    }
};

const int MAXN = 1e5 + 3;
Point points[MAXN];
int tree[4 * MAXN], lazy[4 * MAXN];

bool cmp_by_x(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool cmp_by_y(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

void push_lazy(int ind) {
    tree[2 * ind] += lazy[ind];
    lazy[2 * ind] += lazy[ind];
    
    tree[2 * ind + 1] += lazy[ind];
    lazy[2 * ind + 1] += lazy[ind];

    lazy[ind] = 0;
}

void update_tree(int ind, int tl, int tr, int l, int r, int val) {
    if (l > tr or r < tl or l > r) {
        return;
    }

    if (l == tl and r == tr) {
        tree[ind] += val;
        lazy[ind] += val;
        return;
    }

    push_lazy(ind);

    int mid = (tl + tr) / 2;
    update_tree(2 * ind, tl, mid, l, min(r, mid), val);
    update_tree(2 * ind + 1, mid + 1, tr, max(l, mid + 1), r, val);

    tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
}

void compress_y(int n, int h) {
    sort(points, points + n, cmp_by_y);

    int l = 0;
    for (int r = 0; r < n; ++r) {
        if (r > 0 and points[r - 1].y == points[r].y) {
            points[r].lowest = points[r -1].lowest;
        } else {
            points[r].lowest = r;
        }

        while (l < r and points[r].y - points[l].y > h) {
            points[l++].highest = r - 1;
        }
    }
    
    while (l < n) {
        points[l++].highest = n - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w, h;
    cin >> n >> w >> h;

    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    compress_y(n, h);

    sort(points, points + n, cmp_by_x);
    int res = 0;
    
    int l = 0;
    for (int r = 0; r < n; ++r) {
        update_tree(1, 0, n - 1, points[r].lowest, points[r].highest, 1);
        
        while (l < r and points[r].x - points[l].x > w) {
            update_tree(1, 0, n - 1, points[l].lowest, points[l].highest, -1);
            ++l;
        }

        res = max(res, tree[1]);
    }

    cout << res << endl;
return 0;
}