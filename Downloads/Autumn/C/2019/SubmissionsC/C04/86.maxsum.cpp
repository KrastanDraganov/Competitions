#include<iostream>

using namespace std;
const int N_max = 100010;
const int INF = 1000000000;
int n, k, l[N_max], r[N_max], a[N_max], jump[N_max], maxl[N_max], maxr[N_max];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= k; i ++)
        cin >> jump[i];

    l[0] = -INF;
    l[1] = a[1];
    for (int i = 2; i <= n; i ++)
    {
        for (int j = 1; j <= k; j ++)
            if (i - jump[j] >= 1 && l[i - jump[j]] > l[i])
                l[i] = l[i - jump[j]];
        if (l[i] != 0)
            l[i] += a[i];
        else
            l[i] = -INF;
    }

    r[n + 1] = -INF;
    r[n] = a[n];
    for (int i = n - 1; i > 0; i --)
    {
        for (int j = 1; j <= k; j ++)
            if (i + jump[j] <= n && r[i + jump[j]] > r[i])
                r[i] = r[i + jump[j]];
        if (r[i] != 0)
            r[i] += a[i];
        else
            r[i] = -INF;
    }

    for (int i = 1; i <= n; i ++)
    {
        maxl[i] = l[i];
        if (maxl[i - 1] > maxl[i])
            maxl[i] = maxl[i - 1];
    }

    for (int i = n; i > 0; i --)
    {
        maxr[i] = r[i];
        if (maxr[i + 1] > maxr[i])
            maxr[i] = maxr[i + 1];
    }

    int ans = 2 * (-INF);
    for (int i = 1; i < n; i ++)
    {
        int sum = maxl[i] + maxr[i + 1];
        if (sum > ans)
            ans = sum;
    }
    cout << ans << endl;

    return 0;
}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2
*/
