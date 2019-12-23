#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

ll gcd(ll x, ll y)
{
    if(x < y) swap(x, y);
    return (y == 0) ? x : gcd(y, x % y);
}

ll A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll p, q, g;

    cin >> A >> B;
    if(A > B)
        swap(A, B);

    g = gcd(A, B);
    p = A / g; q = B / g;

    ll y = (q - 1) / p;
    y = min(y, A / q);
    cout << y << endl;

    return 0;
}
