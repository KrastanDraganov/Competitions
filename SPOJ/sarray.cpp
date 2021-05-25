#include <iostream>
#include <vector>
#include <array>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN = 1e5 + 3;
 
struct Suffix {
    int ind;
    array<int, 2> rank;
};
 
void count_sort(int type, vector<Suffix>& suffixes, int n) {
    vector<int> counter(MAXN, 0);
    for (Suffix& curr : suffixes) {
        ++counter[curr.rank[type]];    
    }
 
    vector<int> pos(MAXN, 0);
    for (int i = 1; i < MAXN; ++i) {
        pos[i] = pos[i - 1] + counter[i - 1];
    }
 
    vector<Suffix> res(n);
    for (Suffix& curr : suffixes) {
        res[pos[curr.rank[type]]] = curr;
        ++pos[curr.rank[type]];
    }
 
    for (int i = 0; i < n; ++i) {
        suffixes[i] = res[i];
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
    cin >> s;
 
    int n = (int) s.size();
    
    int pow_limit = 0;
    while ((1 << pow_limit) < n) {
        ++pow_limit;
    }
 
    vector<vector<int>> suffix_order(n, vector<int>(pow_limit + 1, 0));
    for (int i = 0; i < n; ++i) {
        suffix_order[i][0] = s[i];
    }
 
    vector<Suffix> suffixes(n);
    for (int degree = 1; degree <= pow_limit; ++degree) {
        int curr_pow = 1 << (degree - 1);
        
        for (int i = 0; i < n; ++i) {
            suffixes[i].ind = i;
            suffixes[i].rank[0] = suffix_order[i][degree - 1];
            suffixes[i].rank[1] = (i + curr_pow < n ? suffix_order[i + curr_pow][degree - 1] : 0);
        }
 
        count_sort(1, suffixes, n);
        count_sort(0, suffixes, n);
 
        int curr_rank = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 and suffixes[i - 1].rank != suffixes[i].rank) {
                ++curr_rank;
            }
 
            suffix_order[suffixes[i].ind][degree] = curr_rank;
        }
    }
 
    for (int i = 0; i < n; ++i) {
        cout << suffixes[i].ind << endl;
    }
return 0;
} 