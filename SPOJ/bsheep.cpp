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
        if (y == comp.y) {
            if (x == comp.x) {
                return ind < comp.ind;
            }

            return x < comp.x;
        }

        return y < comp.y;
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

        vector<Point> new_points;
        for (int i = 0; i < n; ++i) {
            if (i > 0 and points[i] == points[i - 1]) {
                continue;
            }

            new_points.push_back(points[i]);
        }

        points = new_points;
        n = (int) new_points.size();

        if (n == 1) {
            cout << 0.0 << endl << points[0].ind + 1 << endl << endl;
            continue;
        }

        Point start_point = points[0];
        Point end_point = points[n - 1];

        vector<Point> left_hull = {start_point};
        int left_size = 1;

        vector<Point> right_hull = {start_point};
        int right_size = 1;

        for (int i = 1; i < n; ++i) {
            // Find Left Hull
            if (i == n - 1 or signed_area(start_point, points[i], end_point) < 0) {
                while (left_size >= 2 and signed_area(left_hull[left_size - 2], left_hull[left_size - 1], points[i]) >= 0) {
                    left_hull.pop_back();
                    --left_size;
                }

                left_hull.push_back(points[i]);
                ++left_size;
            }

            // Find Right Hull
            if (i == n -1 or signed_area(start_point, points[i], end_point) > 0) {
                while (right_size >= 2 and signed_area(right_hull[right_size - 2], right_hull[right_size - 1], points[i]) <= 0) {
                    right_hull.pop_back();
                    --right_size;
                }

                right_hull.push_back(points[i]);
                ++right_size;
            }
        }

        vector<Point> convex_hull;
        int hull_size = left_size + right_size - 2;
        
        for (int i = 0; i < right_size; ++i) {
            convex_hull.push_back(right_hull[i]);
        }
        for (int i = left_size - 2; i > 0; --i) {
            convex_hull.push_back(left_hull[i]);
        }

        double circumference = 0;
        for (int i = 1; i < hull_size; ++i) {
            circumference += sqrt(dist_square(convex_hull[i], convex_hull[i - 1]));
        }
        circumference += sqrt(dist_square(convex_hull[0], convex_hull.back()));

        cout << fixed << setprecision(2) << circumference << endl;
        for (Point& point : convex_hull) {
            cout << point.ind + 1 << " ";
        }
        cout << endl << endl;
    }
return 0;
}