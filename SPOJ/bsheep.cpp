#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>

#define endl '\n'

using namespace std;

struct Point {
    int x, y;
    int ind;

    bool operator<(const Point& comp) {
        if (x == comp.x) {
            if (y == comp.y) {
                return ind < comp.ind;
            }

            return y < comp.y;
        }

        return x < comp.x;
    }

    bool operator==(const Point& comp) {
        return x == comp.x and y == comp.y;
    }
};

// Negative - clockwise
// Zero - collinear
// Positive - counterclockwise
int signed_area(Point& a, Point& b, Point& c) {
    return a.x * b.y + a.y * c.x + b.x * c.y
         - a.y * b.x - a.x * c.y - b.y * c.x;
}

int dist_square(Point& a, Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; ++test) {
        int n;
        cin >> n;

        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
            points[i].ind = i;
        }

        sort(points.begin(), points.end());

        for (int i = 0; i < n; ++i) {
            if (i > 0 and points[i] == points[i - 1]) {
                points[i].ind = points[i - 1].ind;
            }
        }

        vector<Point> convex_hull(n);
        int hull_size = 0;

        // Find Upper Hill
        for (int i = 0; i < n; ++i) {
            while (hull_size >= 2 and signed_area(convex_hull[hull_size - 2], convex_hull[hull_size - 1], points[i]) >= 0) {
                --hull_size;
            }

            convex_hull[hull_size] = points[i];
            ++hull_size;
        }

        // Find Lower Hill
        for (int i = n - 1; i >= 0; --i) {
            while (hull_size >= 2 and signed_area(convex_hull[hull_size - 2], convex_hull[hull_size - 1], points[i]) >= 0) {
                --hull_size;
            }

            convex_hull[hull_size] = points[i];
            ++hull_size;
        }

        --hull_size;
        convex_hull.resize(hull_size);
        reverse(convex_hull.begin(), convex_hull.end());

        int circumference = 0;
        for (int i = 1; i < hull_size; ++i) {
            circumference += dist_square(convex_hull[i], convex_hull[i - 1]);
        }

        if (hull_size > 2) {
            circumference += dist_square(convex_hull[0], convex_hull[n - 1]);
        }

        cout << fixed << setprecision(2) << sqrt(circumference) << endl;
        for (Point& point : convex_hull) {
            cout << point.ind + 1 << " ";
        }
        cout << endl << endl;

        // cout << "Convex Hull:\n";
        // for (Point& point : convex_hull) {
        //     cout << point.x << " " << point.y << endl;
        // }
    }
return 0;
}