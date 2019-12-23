#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, k, a[100010], b[1010];

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

    cout << a[1]+a[n] << endl;

    return 0;
}
