#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

void solve(int k) {
    int n;
    cin >> n;
    
    vector<int> big_piles(n), small_piles(n);
    int sum = 0, counter1 = 0;

    for (int i = 0; i < n; ++i) {
        cin >> big_piles[i] >> small_piles[i];
        
        small_piles[i] += big_piles[i];
        sum += small_piles[i];

        if (small_piles[i] == 1) {
            ++counter1;
        } 
    }

    if (counter1 % 2 == 1) {
        cout << "Win\n";
    } else {
        cout << "Loss\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, q;
    cin >> k >> q;

    for (int test = 0; test < q; ++test) {
        solve(k);
    }
return 0;
}