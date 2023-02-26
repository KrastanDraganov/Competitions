#include <iostream>
#include <stack>
#include <string>

#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<int> indexes;
    indexes.push(-1);

    int res = 0;
    for (int i = 0; i < (int) s.size(); ++i)
    {
        if (s[i] == '(')
        {
            indexes.push(i);
        }
        else
        {
            indexes.pop();

            if (indexes.empty())
            {
                indexes.push(i);
            }
            else
            {
                res = max(res, i - indexes.top());
            }
        }
    }

    cout << res << endl;

    return 0;
}