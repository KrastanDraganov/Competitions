#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

struct polb
{
    long long posl, posr;
};

long long n, k;
long long a[1020000];
long long pr[2][1020000];
long long f=0;
stack<long long> izch;
polb sp[1020000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ///
    cin>>n;
    for(long long i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>k;
    for(long long i=0; i<k; i++)
    {
        cin>>pr[0][i]>>pr[1][i];
        a[pr[0][i]]+=pr[1][i];
    }
    long long vis=0;
    for(long long i=0; i<n; i++)
    {
        if(izch.empty())
        {
            f=a[i];
            izch.push(i);
        }
        else
        {
            if(a[i]>=f)
            {
                while(izch.size()>1) izch.pop();
                vis+=(long long)(i-izch.top())*f;
                izch.pop();
                f=a[i];
                izch.push(i);
            }
            else
            {
                while(a[i]>=a[izch.top()]) izch.pop();
                izch.push(i);
            }
        }
    }
    while(izch.size()>1)
    {
        long long t=izch.top();
        izch.pop();
        vis+=(long long)(t-izch.top())*a[t];
    }
    izch.pop();

    ///
    for(long long i=0; i<n; i++) sp[i].posl=sp[i].posr=-1;

    long long nbl=0;
    for(long long i=1; i<n; i++)
    {
        sp[i].posl=nbl;
        if(a[i]>a[nbl]) nbl=i;
    }

    long long nbd=n-1;
    for(long long i=n-2; i>=0; i--)
    {
        sp[i].posr=nbd;
        if(a[i]>a[nbd]) nbd=i;
    }
    ///

    long long brnen=0;
    for(long long i=0; i<k; i++)
    {
        ///pr[0][i]
        long long nom=pr[0][i], v=pr[1][i];
        if(nom==1)
        {
            if(a[sp[nom].posr]<=a[nom]-v)
            {
                brnen++;
                a[nom]-=v;
            }
        }
        else if(nom==n-1)
        {
            if(a[sp[nom].posl]<=a[nom]-v)
            {
                brnen++;
                a[nom]-=v;
            }
        }
        else
        {
            if(a[sp[nom].posl]==a[sp[nom].posr])
            {
                brnen++;
                a[nom]-=v;
            }
            else if(a[sp[nom].posl]<=a[nom]-v && a[sp[nom].posr]<=a[nom]-v)
            {
                a[nom]-=v;
                brnen++;
            }
            else if(a[nom]<=a[sp[nom].posl] && a[nom]<=a[sp[nom].posr])
            {
                brnen++;
                a[nom]-=v;
            }
        }
    }
    cout<<k-brnen<<" "<<vis<<endl;
    return 0;
}

/**
6
2 4 2 4 2 1
2
2 1
4 1
*/
