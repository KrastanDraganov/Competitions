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
    vector<vector<int>> dp(2, vector<int>(limit + 1, 0));
    dp[0][1] = 1;

    for (int i = 1; i < n; ++i) {
        int curr = i & 1;
        int prev = curr ^ 1;

        for (int open_brackets = 0; open_brackets <= limit; ++open_brackets) {
            dp[curr][open_brackets] = 0;
        }

        if (s[i] == '(' or s[i] == '?') {
            for (int open_brackets = 0; open_brackets <= min(i, limit - 1); ++open_brackets) {
                add_mod(dp[curr][open_brackets + 1], dp[prev][open_brackets]);
            }
        }

        if (s[i] == ')' or s[i] == '?') {
            for (int open_brackets = 1; open_brackets <= min(i, limit); ++open_brackets) {
                add_mod(dp[curr][open_brackets - 1], dp[prev][open_brackets]);
            }
        }
    }

    int last_pos = (n - 1) & 1;
    return dp[last_pos][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << fast_sol(s) << endl;
return 0;
}