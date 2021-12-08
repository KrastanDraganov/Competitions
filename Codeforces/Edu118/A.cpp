#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

void solve() {
    int64_t x1, x2;
    int y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int miny = min(y1, y2);
    y1 -= miny;
    y2 -= miny;

    if (y1 > 6) {
        cout << ">\n";
        return;
    }

    if (y2 > 6) {
        cout << "<\n";
        return;
    }

    for (int i = 0; i < y1; ++i) {
        x1 *= 10;
    }
    for (int i = 0; i < y2; ++i) {
        x2 *= 10;
    }

    if (x1 < x2) {
        cout << "<\n";
    } else if (x1 > x2) {
        cout << ">\n";
    } else {
        cout << "=\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; ++test) {
        solve();
    }
return 0;
}
