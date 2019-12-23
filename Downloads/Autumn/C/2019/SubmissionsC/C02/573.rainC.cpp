#include<iostream>
#include<algorithm>
#include<queue>
//#include<vetor>
#include<map>
#include<stack>

using namespace std;

int a[1000005];

int b[1000005];

int maxb[1000005];

int depth[1000005];

bool matter[1000005];

int n,k;

int maxx = 1;

int again()
{
    for(int i = 1;i <= maxx;i++)
    {
        int start = -1,finish = -1;

        for(int j = 0;j < n;j++)
        {
            //cout<<a[j]<<endl;
            if(a[j] >= i)
            {
                start = j;
                break;
            }
        }

        for(int j = n;j >= 0;j--)
        {
            if(a[j] >= i)
            {
                finish = j;
                break;
            }
        }

        for(int j = start;j < finish;j++)
        {
            depth[j] = i;
        }
    }

    int zb = 0;

    for(int i = 0; i < n - 1; i++)
    {
        zb += depth[i];
    }

    return zb;
}

int main()
{

    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    cin>>k;

    for(int i = 0; i < k; i++)
    {
        cin>>b[i]>>maxb[i];
        a[b[i]] += maxb[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(a[i] > maxx)
        {
            maxx = a[i];
        }
    }

    int br = k;

    int zb = again();

    for(int i = 0;i < k;i++)
    {
        if(b[i] != 0&&b[i] < n - 1)
        {
            if(depth[b[i]] == depth[b[i] - 1])
            {
                br--;
            }
            else if(depth[b[i]] <= a[b[i]] - maxb[i]&&depth[b[i] - 1] <= a[b[i]] - maxb[i])
            {
                br--;
            }
        }
        else if(b[i] == 0)
        {
            if(depth[b[i]] <= a[b[i]] - maxb[i])
            {
                br--;
            }
        }
        else if(b[i] == n - 1)
        {
            if(depth[b[i] - 1] <= a[b[i]] - maxb[i])
            {
                br--;
            }
        }
    }

    cout<<br<<" "<<zb<<endl;
}

/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
