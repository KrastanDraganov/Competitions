#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 1000;

int n;
bool edge[MAX_N][MAX_N];

vector<int> path;

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

    path.push_back(0);

    for(int i = 1; i < n; ++i) {
        if(edge[path[path.size() - 1]][i]) {
            path.push_back(i);
        }
        else if(edge[i][path[0]]) {
            path.insert(path.begin(), i);
        }
        else {
            for(int j = 0; true; ++j) {
                if(edge[path[j]][i] && edge[i][path[j + 1]]) {
                    path.insert(path.begin() + (j + 1), i);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }

    cout << endl;

    return 0;
}
