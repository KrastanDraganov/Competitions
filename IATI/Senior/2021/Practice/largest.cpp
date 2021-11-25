#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

struct Rectangle {
    int x, y;
    
    Rectangle() {
        x = y = 0;
    }
    
    Rectangle(int _x, int _y) {
        x = _x;
        y = _y;
    }
    
    bool operator<(const Rectangle& comp) {
        if (x == comp.x) {
            return y < comp.y;
        }
    
        return x < comp.x;
    }
};

int find_lis(vector<int>& nums) {
    vector<int> dp;

    for (int num : nums) {
        if (dp.empty() or num > dp.back()) {
            dp.push_back(num);
            continue;
        }

        int target = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
        dp[target] = num;
    }

    return (int) dp.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Rectangle> rectangles(n);
    for (int i = 0; i < n; ++i) {
        cin >> rectangles[i].x >> rectangles[i].y;
    }

    sort(rectangles.begin(), rectangles.end());

    vector<int> y_axes;
    for (int i = 0; i < n; ++i) {
        y_axes.push_back(rectangles[i].y);
    }

    reverse(y_axes.begin(), y_axes.end());

    cout << find_lis(y_axes) << endl;
return 0;
}