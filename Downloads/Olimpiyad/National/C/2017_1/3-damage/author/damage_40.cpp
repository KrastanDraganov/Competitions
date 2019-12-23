#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int a[maxn][maxn];
bool used[maxn][maxn];
int n, m;
int x11[6] = {-1,  0, -1, 1, -1, 0};
int y11[6] = {-1, -1,  0, 0,  1, 1};
int x2[6] = { 0,  1, -1, 1,  0, 1};
int y2[6] = {-1, -1,  0, 0,  1, 1};


struct Node {
    int x, y;
    long long d;

    Node(int _x, int _y, long long _d) {
        x = _x;
        y = _y;
        d = _d;
    }
};

struct Cmp {
  bool operator()(const Node & lhs, const Node & rhs) const {
    return lhs.d > rhs.d;
  }
};

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[i][j];
        }
        if (j % 2 == 1) {
            cin >> a[n][j];
        } else {
            a[n][j] = 0;
        }
    }
    n++;

    vector<Node> pq;

    for(int j = 0; j < m; j++) {
        pq.push_back(Node(0, j, abs(a[0][j])) );
    }

    while(!pq.empty()) {

        auto it = max_element(pq.begin(),pq.end(), Cmp());
        Node curr = *it;
        pq.erase(it);

        if(curr.x == -1 && curr.y == -1) {
            cout << curr.d << "\n";
            return 0;
        }
        if(used[curr.x][curr.y]) continue;
        used[curr.x][curr.y] = true;

        for (int i = 0; i < 6; i++) {
            int xx,yy;
            if(curr.y%2 == 1) {
                xx = curr.x+ x11[i];
                yy = curr.y + y11[i];
            } else {
                xx = curr.x+ x2[i];
                yy = curr.y + y2[i];
            }
            if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
                if(!used[xx][yy])
                    pq.push_back(Node(xx, yy, curr.d + abs(a[curr.x][curr.y] - a[xx][yy]) ));
            } else if (xx == n) {
                pq.push_back(Node(-1, -1, curr.d + abs(a[curr.x][curr.y])));
            }
        }
    }

    return 0;
}
