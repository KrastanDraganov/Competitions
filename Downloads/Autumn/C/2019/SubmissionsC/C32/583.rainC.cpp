#include <iostream>
using namespace std;
int main ()
{
    int n, k;
    cin >> n;
    int t[n];

    int obem=0;
    cin >> t[0];
    int maxs;
    for (int i=1; i<n; i++)
    {
        cin >> t[i];
        obem=obem+t[i];
        if (t[i]>maxs)
            maxs=t[i];
    }
    cin >> k;
    int c1, c2;
    int br=0;
    for (int i=0; i<k; i++)
    {
        cin >> c1 >> c2;
        if (t[c1]+c2!=maxs && ((t[c1-1]>t[c1]+c2 && t[c1]+c2>t[c1+1]) || (t[c1-1]<t[c1]+c2 && t[c1]+c2<t[c1+1])))
        {
            br++;
            t[c1]=t[c1]+c2;
        }
    }



    for (int i=2; i<n; i++)
    {
        if (t[i-1]<t[i] && t[i-1]<t[i-2])
        obem=obem-t[i-1];
    }
    cout << br << " " << obem << endl;
    return 0;
}
