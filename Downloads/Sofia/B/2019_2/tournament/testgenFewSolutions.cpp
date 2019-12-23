#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_N = 10000;

int n;
bool edge[MAX_N][MAX_N];
int outCount[MAX_N];

int order[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);

    int seed;
    cerr << "Seed for rand: ";
    cin >> seed;
    srand(seed);

    cerr << "N: ";
    cin >> n;
    cout << n << "\n";

    int randomEdgeCount;
    cerr << "Random edges: ";
    cin >> randomEdgeCount;

    for(int i = 0; i < n; ++i) {
        order[i] = i;
    }

    random_shuffle(order, order + n);

    cerr << "Order:\n";
    for(int i = 0; i < n; ++i) {
        cerr << order[i] << " ";
    }
    cerr << endl;

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int v1 = order[i];
            int v2 = order[j];

            edge[v1][v2] = true;
            edge[v2][v1] = false;

            outCount[v1] += (edge[v1][v2] ? 1 : 0);
            outCount[v2] += (edge[v2][v1] ? 1 : 0);
        }
    }

    for(int i = 0; i < randomEdgeCount; ++i) {
        int v1 = rand() % n;
        int v2 = rand() % n;

        while(v1 == v2) {
            v2 = rand() % n;
        }

        outCount[v1] += (edge[v1][v2] ? -1 : 1);
        edge[v1][v2] = !edge[v1][v2];

        outCount[v2] += (edge[v2][v1] ? -1 : 1);
        edge[v2][v1] = !edge[v2][v1];
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
