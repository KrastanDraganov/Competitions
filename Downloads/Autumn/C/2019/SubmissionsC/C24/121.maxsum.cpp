#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

const int Infm=-1e9;

int n, k;
int a[100100], l[100100], r[100100], m[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i], l[i]=Infm, r[i]=Infm;
    for(int i=1; i<=k; i++) cin>>m[i];
    l[1]=a[1];
    for(int i=2; i<n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i-m[j]>=1 && l[i]<l[i-m[j]]+a[i]) l[i]=l[i-m[j]]+a[i];
        }
    }
    r[n]=a[n];
    for(int i=n-1; i>1; i--)
    {
        for(int j=1; j<=k; j++)
        {
            if(i+m[j]<=n && r[i]<r[i+m[j]]+a[i]) r[i]=r[i+m[j]]+a[i];
        }
    }
    for(int i=2; i<n; i++) l[i]=max(l[i], l[i-1]);
    for(int i=n-1; i>1; i--) r[i]=max(r[i], r[i+1]);
    int maxbr=0;
    for(int i=1; i<n; i++) maxbr=max(maxbr, l[i]+r[i+1]);
    cout<<maxbr<<endl;
    return 0;
}
/**
9 2
3 2 6 6 0 2 4 5 5
3 2

6 2
1 4 7 2 5 1
3 4
*/
