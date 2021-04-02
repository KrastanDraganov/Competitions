#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;

void add_mod(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int brute_force(string& s) {
    int n = (int) s.size();

    int res = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int balance = 0;
        for (int i = 0; i < n; ++i) {
            bool curr = (mask & (1 << i));
            if ((s[i] == '(' and curr == 1) or (s[i] == ')' and curr == 0)) {
                balance = -1;
                break;
            }

            balance += (curr == 0 ? 1 : -1);
            if (balance < 0) {
                break;
            }
        }

        if (balance == 0) {
            ++res;
        }
    }

    return res;
}

int fast_sol(string& s) {
    int n = (int) s.size();
    if (s[0] == ')' or n % 2 == 1) {
        return 0;
    }

    int limit = n / 2;
    vector<vector<int>> dp(n, vector<int>(limit + 1, 0));
    dp[0][1] = 1;

    for (int i = 1; i < n; ++i) {
        if (s[i] == '(' or s[i] == '?') {
            for (int counter = 0; counter <= min(i, limit - 1); ++counter) {
                add_mod(dp[i][counter + 1], dp[i - 1][counter]);
            }
        }

        if (s[i] == ')' or s[i] == '?') {
            for (int counter = 1; counter <= min(i, limit); ++counter) {
                add_mod(dp[i][counter - 1], dp[i - 1][counter]);
            }
        }
    }

    return dp[n - 1][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << fast_sol(s) << endl;
    // cout << brute_force(s) << endl;
return 0;
}