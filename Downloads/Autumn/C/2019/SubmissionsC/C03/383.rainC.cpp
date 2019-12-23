#include <iostream>
#include <cmath>
using namespace std;
const long long int MAXN = 1000001;
long long int n,k,a[MAXN], p[MAXN], h[MAXN], h1[MAXN];
long long int find_V()
{
    long long int ans = 0;
    for(long long int i=0; i<n-1; i++)
    {
        ans+=h[i];
    }
    return ans;
}
long long int make_levels()
{
    long long int j, sum = 0;
    for(long long int i=0; i<n-1; i++)
    {
        j = i+1;
        if(a[i] <= a[j])
        {
            h1[i] = a[i];
            sum+=h1[i];
        }
        else
        {
            while(a[j]<a[i] && a[j]<a[j+1])
            {
                j++;
            }
            h1[i] = a[i];
            if(a[j]<h1[i])
            {
                h1[i] = a[j];
            }
            sum+=h1[i];
            for(long long int l=i+1; l<j; l++)
            {
                h1[l] = h1[i];
                sum+=h1[i];

            }
            i = j-1;
        }
    }
    return sum;
}
void read()
{
    cin >> n;
    for(long long int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    long long int j, sum = 0;
    for(long long int i=0; i<n-1; i++)
    {
        j = i+1;
        if(a[i] <= a[j])
        {
            h[i] = a[i];
            sum+=h[i];
        }
        else
        {
            while(a[j]<a[i] && a[j]<a[j+1])
            {
                j++;
            }
            h[i] = a[i];
            if(a[j] < h[i])
            {
                h[i] = a[j];
            }
            sum+=h[i];
            for(long long int l=i+1; l<j; l++)
            {
                h[l] = h[i];
                sum+=h[i];
            }
            i = j-1;
        }
    }
    cin >> k;
    long long int x,y,cnt = 0;
    for(long long int i=0; i<k; i++)
    {
        cin >> x >> y ;
        a[x] += y;
        long long int k = make_levels();
        if(k > sum)
        {
            cnt++;
            sum = k;
        }
        else
        {
            a[x] -= y;
        }
    }
    cout << cnt << " " << sum << endl;
}
int main()
{
    read();
    return 0;
}
