#include<iostream>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    
    int n = (int) s.size();
    vector<int> prefix(n, 0);

    for (int i = 1; i < n; ++i) {
        int curr = prefix[i - 1];
        while (curr > 0 and s[i] != s[curr]) {
            curr = prefix[curr - 1];
        }

        if (s[i] == s[curr]) {
            ++curr;
        }

        prefix[i] = curr;

        int pos = i + 1;
        if (prefix[i] != 0 and pos % (pos - prefix[i]) == 0) {
            cout << pos << " " << pos - prefix[i] << endl;
        }
    }
return 0;
}