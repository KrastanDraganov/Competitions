#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m;
int h[N], a[N];

int pref[N], suff[N];
int cnt_increase, inc[N];
ll ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        cin >> a[x + 1];
    }

    pref[1] = 1;
    for(int i = 2; i <= n; i++)
        if(h[i] + a[i] > h[pref[i - 1]] + a[pref[i - 1]])
            pref[i] = i;
        else
            pref[i] = pref[i - 1];

    suff[n] = n;
    for(int i = n - 1; i >= 1; i--)
        if(h[i] + a[i] > h[suff[i + 1]] + a[suff[i + 1]])
            suff[i] = i;
        else
            suff[i] = suff[i + 1];

    for(int i = 1; i <= n; i++)
    {
        int l = h[pref[i - 1]] + a[pref[i - 1]], r = h[suff[i + 1]] + a[suff[i + 1]];
        if(min(l, r) >= h[i] + a[i] || max(l, r) <= h[i])
            continue;
        else
        {
            if(a[i] != 0)
            {
                cnt_increase++;
                inc[i] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++)
        if(inc[i])
            h[i] += a[i];

    pref[1] = 1;
    for(int i = 2; i <= n; i++)
        if(h[i] > h[pref[i - 1]])
            pref[i] = i;
        else
            pref[i] = pref[i - 1];

    suff[n] = n;
    for(int i = n - 1; i >= 1; i--)
        if(h[i] > h[suff[i + 1]])
            suff[i] = i;
        else
            suff[i] = suff[i + 1];

    int last = pref[n];
    while(last != n)
    {
        ans += 1LL * (suff[last + 1] - last) * h[suff[last + 1]];
        last = suff[last + 1];
    }

    last = pref[n];
    while(last != 1)
    {
        ans += 1LL * (last - pref[last - 1]) * h[pref[last - 1]];
        last = pref[last - 1];
    }

    cout << cnt_increase << " " << ans << endl;

    return 0;
}

/*

6
2 4 2 4 2 1
2
2 1
4 1

*/
