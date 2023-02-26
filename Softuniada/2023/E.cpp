#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

bool cmp(string& a, string& b)
{
    int n = (int) a.size();
    int m = (int) b.size();
    
    for (int i = 0; i < min(n, m); ++i)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i];
        }
    }

    if (n > m)
    {
        return a[m] > b[0];
    }
    else if (m > n)
    {
        return b[n] < a[0];
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    vector<string> all;

    while (cin >> s)
    {
        all.push_back(s);
    }

    sort(all.begin(), all.end(), cmp);

    for (string num : all)
    {
        cout << num;
    }
    cout << endl;

    return 0;
}