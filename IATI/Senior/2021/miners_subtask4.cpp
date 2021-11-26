#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

struct Mine {
    int counter, limit;

    Mine() : counter(0), limit(0) {}
    Mine(int _counter, int _limit) : counter(_counter), limit(_limit) {}
};

const int MAXN = 5e5 + 3;
Mine mines[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> mines[i].counter;
    }
    for (int i = 0; i < n; ++i) {
        cin >> mines[i].limit;
    }

    vector<int> grades(n);
    for (int i = 0; i < n - 1; ++i) {
        int from;
        cin >> from >> grades[i];
    }

    grades[n - 1] = -1;
    
    int64_t res = 0;
    vector<int> positive_grades;

    for (int i = 0; i < n; ++i) {
        if (grades[i] >= 0) {
            positive_grades.push_back(grades[i]);
            continue;
        }

        int group_size = (int) positive_grades.size();
        int middle = (group_size + 1) / 2;

        int factor = 1;
        for (int j = 0; j < middle; ++j, ++factor) {
            res += 1ll * positive_grades[j] * factor;
        }
        
        --factor;
        if (group_size % 2 == 1) {
            --factor;
        }

        for (int j = middle; j < group_size; ++j, --factor) {
            res += 1ll * positive_grades[j] * factor;
        }

        positive_grades.clear();
    }

    cout << res << endl;
return 0;
}