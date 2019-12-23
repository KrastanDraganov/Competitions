#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

const int MAX_N = 10000;

int n;
bool edge[MAX_N][MAX_N];
int outCount[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);

    int seed;
    cerr << "Seed for rand: ";
    cin >> seed;
    srand(seed);

    cerr << "N: ";
    cin >> n;
    cout << n << "\n";

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            edge[i][j] = (rand() % 2 == 0);
            edge[j][i] = !edge[i][j];

            outCount[i] += (edge[i][j] ? 1 : 0);
            outCount[j] += (edge[j][i] ? 1 : 0);
        }
    }

    cin.tie(0);

    for(int i = 0; i < n; ++i) {
        cout << outCount[i];

        if(outCount[i] > 0) {
            cout << " ";
        }

        for(int j = 0; j < n; ++j) {
            if(edge[i][j]) {
                --outCount[i];
                cout << j << (outCount[i] > 0 ? " ": "");
            }
        }

        cout << "\n";
    }

    return 0;
}
