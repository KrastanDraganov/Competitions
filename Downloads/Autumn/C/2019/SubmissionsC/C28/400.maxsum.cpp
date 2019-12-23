#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[100002], b[1003];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    int sum=0;
    for (int i=0; i<N; i++) cin >> a[i], sum+=a[i];
    for (int i=0; i<K; i++) cin >> b[i];
    cout << sum << endl;
    return 0;
}
