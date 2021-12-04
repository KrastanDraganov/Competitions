#include <iostream>
#include <vector>
#include <set>

#define endl '\n'

using namespace std;

struct Wall {
    int64_t startx, width, height;
    set<pair<int, int>> shots;

    Wall() {
        startx = 0;
        width = 0;
        height = 0;
        shots.clear();
    }

    Wall(int64_t _startx, int64_t _width, int64_t _height) {
        startx = _startx;
        width = _width;
        height = _height;
        shots.clear();
    }
};

void find_shot_target(int64_t shot_x, int64_t shot_y, int n, vector<Wall>& walls) {
    int target_wall = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (shot_x >= walls[i].startx and shot_y <= walls[i].height) {
            target_wall = i;
            break;
        }
    }

    if (target_wall == -1) {
        cout << "MISS\n";
        return;
    }

    set<pair<int, int>>& curr_wall = walls[target_wall].shots;

    pair<int, int> comp = {shot_y, 0};
    auto it = lower_bound(curr_wall.begin(), curr_wall.end(), comp);

    int counter = 1;
    if (it != curr_wall.end() and it->first == shot_y) {
        counter = it->second + 1;
        curr_wall.erase(it);
    }

    cout << "HIT " << walls[target_wall].startx + walls[target_wall].width - counter << " " << target_wall + 1 << " ";

    if (counter == walls[target_wall].width) {
        cout << "YES\n";
        walls[target_wall].height = shot_y - 1;
    } else {
        cout << "NO\n";
        curr_wall.insert({shot_y, counter});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int64_t left_corner = 1;
    vector<Wall> walls(n);

    for (int i = 0; i < n; ++i) {
        int64_t w, h;
        cin >> w >> h;

        walls[i] = Wall(left_corner, w, h);

        left_corner += w + 1;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int64_t x, y;
        cin >> x >> y;

        find_shot_target(x, y, n, walls);
    }
return 0;
}