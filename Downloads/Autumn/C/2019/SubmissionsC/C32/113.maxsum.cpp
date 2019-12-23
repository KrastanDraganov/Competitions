#include <iostream>
using namespace std;
int main ()
{
    int n, k;
    cin >> n >> k;
    int t[n], p[k];

    int sum=0;
    for (int i=0; i<n; i++)
    {
        cin >> t[i];
        sum=sum+t[i];
    }

    for (int i=0; i<k; i++)
        cin >> p[i];

    cout << sum << endl;
    return 0;
}
