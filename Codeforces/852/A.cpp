#include <iostream>
 
#define endl '\n'
 
using namespace std;
 
void solve()
{
    int64_t a, b, n, m;
    cin >> a >> b >> n >> m;
 
    int promo = n / (m + 1);
    int left = n - (m + 1) * promo;
 
    int64_t res = 1ll * promo * min(a * m, b * (m + 1));
    res += left * min(a, b);
 
    cout << res << endl;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tests;
    cin >> tests;
 
    while (tests--)
    {
        solve();
    }
 
    return 0;
}