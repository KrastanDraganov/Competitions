#include <iostream>
 
#define endl '\n'
 
using namespace std;
 
void solve()
{
    int a, b;
    cin >> a >> b;
 
    cout << (a - b) * 2 << endl;
 
    for (int i = b; i <= a; ++i)
    {
        cout << i << " ";
    }
    for (int i = a - 1; i > b; --i)
    {
        cout << i << " ";
    }
    cout << endl;
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