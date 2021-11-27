#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

void only_curious(int n) {
    int middle = (n + 2) / 2;

    cout << middle << endl;
    for (int i = 0; i < middle; ++i) {
        cout << middle << " ";
    }
    cout << endl;
}

void only_scared(int n) {
    if (n == 1) {
        cout << 1 << endl << 1 << endl;
        return;
    }

    if (n == 2) {
        cout << 2 << endl << 1 << " " << 2 << endl;
        return;
    }

    cout << n / 2 + 1 << endl;
    for (int i = 1; i < n; i += 2) {
        cout << i << " ";
    }
    cout << n << endl;
}

void n_steps(int n, int s, int c) {
    cout << n - 1 << endl;
    for (int i = 0; i < n - 2; ++i) {
        if (i % (s + c) < s) {
            cout << 1 << " ";
        } else {
            cout << n << " ";
        }
    }
    cout << n << endl;
}

void find_solution(int ind, int l, int r, int s, int c, vector<int>& solution) {
    if (l == r) {
        solution.push_back(l);
        return;
    }
    
    int mid = (l + r) / 2;
    for (int i = 0; i < mid - l - 1; ++i, ++ind) {
        if (ind % (s + c) < s) {
            solution.push_back(l);
        } else {
            solution.push_back(r);
        }
    }

    find_solution(ind, mid, r, s, c, solution);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, c;
    cin >> n >> s >> c;

    if (s == 0) {
        only_curious(n);
    } else if (c == 0) {
        only_scared(n);
    } else {
        n_steps(n, s, c);
    }
return 0;
}