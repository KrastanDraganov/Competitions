#include <iostream>
#include <array>

#define endl '\n'

using namespace std;

struct Suffix {
    int ind;
    array<int, 2> rank;
};

const int MAXN = 2e5 + 3, MAX_LOG = 20;
int suffix_order[MAXN][MAX_LOG];
Suffix suffixes[MAXN];

int counter[MAXN];
Suffix new_array[MAXN];

void count_sort(int type, int n) {
    for (int i = 0; i < MAXN; ++i) {
        counter[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        ++counter[suffixes[i].rank[type]];
    }

    for (int i = 1; i < MAXN; ++i) {
        counter[i] += counter[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        int curr_pos = --counter[suffixes[i].rank[type]];
        new_array[curr_pos] = suffixes[i];
    }

    for (int i = 0; i < n; ++i) {
        suffixes[i] = new_array[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s += s;

    int n = (int) s.size();
    
    int pow_limit = 0;
    while ((1 << pow_limit) < n) {
        ++pow_limit;
    }

    for (int i = 0; i < n; ++i) {
        suffix_order[i][0] = s[i];
    }

    for (int degree = 1; degree <= pow_limit; ++degree) {
        int curr_pow = 1 << (degree - 1);
        
        for (int i = 0; i < n; ++i) {
            suffixes[i].ind = i;
            suffixes[i].rank[0] = suffix_order[i][degree - 1];
            suffixes[i].rank[1] = (i + curr_pow < n ? suffix_order[i + curr_pow][degree - 1] : 0);
        }

        count_sort(1, n);
        count_sort(0, n);

        int curr_rank = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 and suffixes[i - 1].rank != suffixes[i].rank) {
                ++curr_rank;
            }

            suffix_order[suffixes[i].ind][degree] = curr_rank;
        }
    }

    int target = 0;
    while (target < n and suffixes[target].ind > n / 2) {
        ++target;
    }

    cout << s.substr(suffixes[target].ind, n / 2) << endl;
return 0;
}