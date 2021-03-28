#include<iostream>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pattern;
    cin >> pattern;

    int n = (int) pattern.size();
    vector<int> prefix(n, 0);
    for (int i = 1; i < n; ++i) {
        int curr = prefix[i - 1];
        while (curr > 0 and pattern[i] != pattern[curr]) {
            curr = prefix[curr - 1];
        }

        if (pattern[i] == pattern[curr]) {
            ++curr;
        }

        prefix[i] = curr;
    }

    string text;
    cin >> text;

    int m = (int) text.size();
    int res = 0, matched = 0;
    for (int end_ind = 0; end_ind < m; ++end_ind) {
        while (matched > 0 and text[matched] != text[end_ind]) {
            matched = prefix[matched - 1];
        }

        if (text[matched] != text[end_ind]) {
            matched = 0;
            continue;
        }

        ++matched;
        if (matched == n) {
            ++res;
            matched = prefix[matched - 1];
        }
    }
    
    cout << res << endl;
return 0;
}