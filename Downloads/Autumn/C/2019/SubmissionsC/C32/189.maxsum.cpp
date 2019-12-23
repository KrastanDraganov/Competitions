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

    cin >> p[0];
    if (p[0]==1)
    {
        cout << sum <<endl;
        return 0;
    }

    int mins=p[0];
    for (int i=1; i<k; i++)
    {
        cin >> p[i];
        if (p[i]<mins)
            mins=p[i];
        if (p[i]==1)
        {
            cout << sum <<endl;
            return 0;
        }
    }

    int sum2=t[0]+t[n-1];
    for (int i=0; i<n; i++)
    {
        if (i%mins==0 && i!=0 && i!=n-1)
        {
            sum2=sum2+t[i];
        }
    }
    cout << sum2 << endl;
    return 0;
}
