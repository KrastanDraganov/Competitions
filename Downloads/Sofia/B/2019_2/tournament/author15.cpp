#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_N = 1000;

int n;
bool edge[MAX_N][MAX_N];

int path[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i) {
        int currCount;
        cin >> currCount;
        for(int j = 0; j < currCount; ++j) {
            int to;
            cin >> to;
            edge[i][to] = true;
        }
    }

    for(int i = 0; i < n; ++i) {
        path[i] = i;
    }

    do {
        bool valid = true;

        for(int i = 0; i < n - 1; ++i) {
            if(!edge[path[i]][path[i + 1]]) {
                valid = false;
                break;
            }
        }

        if(valid) {
            break;
        }
    }
    while(next_permutation(path, path + n));

    for(int i = 0; i < n; ++i) {
        cout << path[i] << " ";
    }

    cout << endl;

    return 0;
}
