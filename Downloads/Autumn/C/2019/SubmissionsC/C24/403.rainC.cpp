#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

struct polb
{
    int posl, posr;
    int visl, visr;
};

int n, k;
int a[1020000];
int pr[2][1020000];
int f=0;
stack<int> izch;
polb sp[1020000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ///
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>k;
    for(int i=0; i<k; i++)
    {
        cin>>pr[0][i]>>pr[1][i];
        a[pr[0][i]]+=pr[1][i];
    }
    long long vis=0;
    for(int i=0; i<n; i++)
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
        int t=izch.top();
        izch.pop();
        vis+=(long long)(t-izch.top())*a[t];
    }
    izch.pop();

    ///
    for(int i=0; i<n; i++) sp[i].posl=sp[i].posr=-1;

    int nbl=0;
    for(int i=1; i<n; i++)
    {
        sp[i].posl=nbl;
        sp[i].visl=a[nbl];
        if(a[i]>a[nbl]) nbl=i;
    }

    int nbd=n-1;
    for(int i=n-2; i>=0; i--)
    {
        sp[i].posr=nbd;
        sp[i].visr=a[nbd];
        if(a[i]>a[nbd]) nbd=i;
    }
    ///

    int brnen=0;
    for(int i=0; i<k; i++)
    {
        ///pr[0][i]
        int nom=pr[0][i], v=pr[1][i];
        if(nom==0)
        {
            if(sp[nom].visr<=a[nom]-v)
            {
                brnen++;
                a[nom]-=v;
                cout<<1<<" "<<nom<<endl;
            }
        }
        else if(nom==n-1)
        {
            if(sp[nom].visl<=a[nom]-v)
            {
                brnen++;
                a[nom]-=v;
                cout<<2<<" "<<nom<<endl;
            }
        }
        else
        {
            if(sp[nom].visl==sp[nom].visr)
            {
                brnen++;
                a[nom]-=v;
                cout<<3<<" "<<nom<<endl;
            }
            else if(sp[nom].visl<=a[nom]-v && sp[nom].visr<=a[nom]-v)
            {
                a[nom]-=v;
                brnen++;
                cout<<4<<" "<<nom<<endl;
            }
            else if(a[nom]<=sp[nom].visl && a[nom]<=sp[nom].visr)
            {
                brnen++;
                a[nom]-=v;
                cout<<5<<" "<<nom<<endl;
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

7
3 2 1 6 7 4 2
5
6 1
0 4
2 6
1 6
5 3
*/
