// Not solved - Time Limit, 65 points

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

const int MAXN = 1e3 + 3;
const int MAXK = 13;

string s[MAXK];
int dp[MAXN][MAXN];
int limit_position[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= 2 * n; ++i)
    {
        limit_position[i] = n;
    }

    n = 2 * n - 1;

    for (int i = 0; i < k; ++i)
    {
        cin >> s[i];

        s[i] += s[i];
        s[i][n] = '\0';
    }

    for (int a = 1; a < k; ++a)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[a - 1][i - 1] == s[a][j - 1])
                {
                    dp[i][j] = min(limit_position[i], dp[i - 1][j - 1] + 1);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        for (int j = 1; j <= n; ++j)
        {
            limit_position[j] = 0;
            for (int i = 1; i <= n; ++i)
            {
                limit_position[j] = max(limit_position[j], dp[i][j]);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            res = max(res, dp[i][j]);
        }
    }

    cout << res << endl;

    return 0;
}