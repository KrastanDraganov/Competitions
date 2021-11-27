#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#include "hint.h"

using namespace std;

const int BASE = 97;

vector<bool> genHint(const vector<int>& a, const vector<int>& b, const vector<int>& res) {
    int n = (int) a.size();
    int m = (int) res.size();

    int k = 0;
    int64_t hint_hash = 0;

    for (int i = 0; i < n and k < m; ++i) {
        if (a[i] == res[k]) {
            hint_hash = BASE * hint_hash + i;
            ++k;
        }
    }

    bitset<32> binary_hash(hint_hash);
    bitset<32> binary_size(m);

    cout << binary_hash << endl;
    cout << binary_size << endl;

    vector<bool> hint(64);
    for (int i = 0; i < 32; ++i) {
        hint[i] = binary_hash[32 - i - 1];
    }
    for (int i = 0; i < 32; ++i) {
        hint[i + 32] = binary_size[32 - i - 1];
    }

    for (int i = 0; i < 64; ++i) {
        cout << hint[i];
    }
    cout << endl;

    return hint;
}

vector<int> solve(const vector<int>& a, const vector<int>& b, const vector<bool>& hint) {
    int n = (int) a.size();

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (hint[i]) {
            res.push_back(a[i]);
        }
    }
 
    return res;
}