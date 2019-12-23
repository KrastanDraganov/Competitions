#include <bits/stdc++.h>
using namespace std;

int n, k;
int divs[1000000];
pair<int, int> other[1000000];
pair<bool, int> q[1000000];
int sum, curr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> divs[i];
    }
    cin >> k;
    for (int i = 0; i < k; ++ i) {
        int ind, len;
        cin >> ind >> len;
        q[ind] = { true, len };
        divs[ind] += len;
    }
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = i - 1; j >= 0; -- j) {
            if (divs[i] >= other[j].second || divs[i] >= divs[j]) { other[j] = { i, divs[i] }; }
        }
    }
    for (int i = 0; i < n - 1; ++ i) {
        if (i < curr) { 
            if (q[i].first) { -- k; }
            continue;
        }
        if (q[other[i].first].first) { //is it needed
            if (divs[other[i].first] - q[other[i].first].first <= divs[i] && divs[other[i].first] - q[other[i].first].first <= other[other[i].first].second) {
                other[i] = other[other[i].first];
            } 
        }
        sum += (min(divs[i], other[i].second) * (other[i].first - i));
        curr = other[i].first;
    }
    cout << k << ' ' << sum << endl;
    return 0;
}
/*
7
5 2 3 5 2 3 5
1
3 1
*/