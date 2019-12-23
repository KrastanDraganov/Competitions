#include<iostream>

using namespace std;
const long long N_max = 100010;
const long long INF = 1000000000;

long long n, k, a[N_max], go[N_max], l[N_max], r[N_max], maxL[N_max], maxR[N_max];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (long long i = 1; i <= n; i ++)
        cin >> a[i];

    for (long long i = 1; i <= k; i ++)
        cin >> go[i];

    l[1] = a[1];
    for (long long i = 2; i <= n; i ++)
    {
        l[i] = -INF;
        for (long long j = 1; j <= k; j ++)
            if (i - go[j] > 0 && l[i - go[j]] + a[i] > l[i])
                l[i] = l[i - go[j]] + a[i];
    }

    r[n] = a[n];
    for (long long i = n - 1; i > 0; i --)
    {
        r[i] = -INF;
        for (long long j = 1; j <= k; j ++)
            if (i + go[j] <= n && r[i + go[j]] + a[i] > r[i])
                r[i] = r[i + go[j]] + a[i];
    }

    maxL[1] = l[1];
    for (long long i = 2; i <= n; i ++)
    {
        maxL[i] = maxL[i - 1];
        if (l[i] > maxL[i])
            maxL[i] = l[i];
    }

    maxR[n] = r[n];
    for (long long i = n - 1; i > 0; i--)
    {
        maxR[i] = maxR[i + 1];
        if (r[i] > maxR[i])
            maxR[i] = r[i];
    }

    long long ans = 2 * (-INF);
    for (long long i = 1; i < n; i ++)
    {
        long long sum = maxL[i] + maxR[i + 1];
        if (sum > ans)
            ans = sum;
    }
    cout << ans << endl;
    return 0;
}
