#include <iostream>
using namespace std;
const int MAXN = 100001;
int n,k,a[MAXN], p[MAXN], dp1[MAXN], dp2[MAXN];
bool used1[MAXN], used2[MAXN];
void read()
{
    cin >> n >> k ;
    for(int i=0; i<n; i++)
    {
        cin >> a[i] ;
    }
    dp1[0] = a[0];
    used1[0] = true;
    dp2[n-1] = a[n-1];
    used2[n-1] = true;
    for(int i=0; i<k; i++)
    {
        cin >> p[i];
        dp1[p[i]] = dp1[0]+a[p[i]];
        used1[p[i]] = true;
        dp2[n-1-p[i]] = dp2[n-1]+a[n-1-p[i]];
        used2[n-1-p[i]] = true;
    }
}
void solve()
{
    int l;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            l = i-p[j];
            if(l>=0)
            {
                if(used1[l])
                {
                    if(!used1[i] || dp1[l]+a[i]>dp1[i])
                    {
                        dp1[i] = dp1[l]+a[i];
                        used1[i] = true;
                    }
                }
            }
        }
        dp1[i] = max(dp1[i-1],dp1[i]);
    }
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<k; j++)
        {
            l = i+p[j];
            if(l<n)
            {
                if(used2[l])
                {
                    if(!used2[i] || dp2[l]+a[i]>dp2[i])
                    {
                        dp2[i] = dp2[l]+a[i];
                        used2[i] = true;
                    }
                }
            }
        }
        dp2[i] = max(dp2[i+1],dp2[i]);
    }
    int max1 = dp2[0];
    for(int i=0; i<n-1; i++)
    {
        l = dp1[i]+dp2[i+1];
        if(l > max1)
        {
            max1 = l;
        }
    }
    if(dp1[n-1] > max1)
    {
        max1 = dp1[n-1];
    }
    cout << max1 << endl;
}
int main()
{
    read();
    solve();
    return 0;
}
