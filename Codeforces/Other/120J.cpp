#include <iostream>
#include <set>
#include <utility>
#include <math.h>
#include <algorithm>
#include <fstream>

#define endl '\n'

using namespace std;

struct Vector {
    int x, y;
    int ind;
    int positive_change, negative_change;

    Vector() : x(0), y(0), ind(0), positive_change(0), negative_change(0) {}

    bool operator<(const Vector& comp) {
        if (x == comp.x) {
            return y < comp.y;
        }

        return x < comp.x;
    }
};

const int MAXN = 1e5 + 3;
const int INF = 2e9;

Vector vectors[MAXN];

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> vectors[i].x >> vectors[i].y;
        vectors[i].ind = i + 1;

        if (vectors[i].x >= 0 and vectors[i].y >= 0) {
            vectors[i].positive_change = 1;
            vectors[i].negative_change = 4;
        } else if (vectors[i].x < 0 and vectors[i].y < 0) {
            vectors[i].positive_change = 4;
            vectors[i].negative_change = 1;
        } else if (vectors[i].x < 0) {
            vectors[i].positive_change = 2;
            vectors[i].negative_change = 3;
        } else {
            vectors[i].positive_change = 3;
            vectors[i].negative_change = 2;
        }

        if (vectors[i].x < 0) {
            vectors[i].x = -vectors[i].x;
        }
        if (vectors[i].y < 0) {
            vectors[i].y = -vectors[i].y;
        }
    }

    sort(vectors, vectors + n);

    set<pair<int, int>> sweep_line;
    
    int l = 0;
    int min_dist = INF;
    Vector vector1, vector2;

    for (int r = 0; r < n; ++r) {
        int limit = ceil(sqrt(min_dist));

        while (l < r and vectors[r].x - vectors[l].x >= limit) {
            sweep_line.erase({vectors[l].y, l});
            ++l;
        }

        auto left_it = sweep_line.lower_bound({vectors[r].y - limit, l});
        auto right_it = sweep_line.upper_bound({vectors[r].y + limit, l});

        for (auto it = left_it; it != right_it; ++it) {
            int curr_ind = it->second;

            int diffx = vectors[r].x - vectors[curr_ind].x;
            int diffy = vectors[r].y - vectors[curr_ind].y;

            int curr_dist = diffx * diffx + diffy * diffy;
            
            if (curr_dist < min_dist) {
                min_dist = curr_dist;
                vector1 = vectors[r];
                vector2 = vectors[curr_ind];
            }
        }

        sweep_line.insert({vectors[r].y, r});
    }

    cout << vector1.ind << " " << vector1.positive_change << " ";
    cout << vector2.ind << " " << vector2.negative_change << endl;

return 0;
}