#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, k, a[100010], b[1010];
unsigned long long s = 0, ms = -1, sum1, sum2, maxsum = -2e9;

void rec1(int i, int m)
{
    if (i > m) return;

    s += a[i];

    ms = max(ms, s);

    for (int j = 1; j <= k; j++)
    {
        rec1(i+b[j], m);
    }
    s -= a[i];
}


void rec2(int i, int m)
{
    if (i <= m) return;

    s += a[i];

    ms = max(ms, s);

    for (int j = 1; j <= k; j++)
    {
        rec2(i-b[j], m);
    }
    s -= a[i];
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    for (int i = 1; i <= 3; i++)
    {
        sum1 = 0, sum2 = 0, ms = -2e9;
        rec1(1, i);
        sum1 = ms;
        ms = 0;
        rec2(n, i);
        sum2 = ms;
        if (sum1+sum2 > maxsum) maxsum = sum1+sum2;
        if (sum1      > maxsum) maxsum = sum1;
        if (sum2      > maxsum) maxsum = sum2;
    }
    cout << maxsum << endl;
    return 0;
}
/**
9 2
3 2 6 6 0 2 4 5 5
3 2
*/
