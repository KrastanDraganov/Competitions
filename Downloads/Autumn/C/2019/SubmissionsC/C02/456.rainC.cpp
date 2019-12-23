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

int again()
{
    for(int i = n - 1; i >= 1; i--)
    {

        int indx = i;
        for(int j = i - 1; j >= 0; j--)
        {
            //cout<<j<<" j "<<a[j]<<endl;
            if(a[j] >= a[i])
            {
                if(depth[j - 1] < j)
                {
                    indx = j;
                }
                break;
            }
        }

        for(int j = indx; j < i; j++)
        {
            //cout<<j<<endl;
            depth[j] = a[i];
        }

        if(i != indx)
        {
            i = indx + 1;
        }
    }

    for(int i = 0; i < n - 1; i++)
    {
        if(depth[i] == 0)
        {
            int indx = i;
            for(int j = i + 1; j < n; j++)
            {
                //cout<<j<<" j "<<a[j]<<endl;
                if(a[j] >= a[i])
                {
                    indx = j;
                    break;
                }
            }

            for(int j = i; j < indx; j++)
            {
                //cout<<j<<endl;
                if(depth[j] < a[i])
                {
                    depth[j] = a[i];
                }
            }

            if(i != indx)
            {
                i = indx - 1;
            }
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

    int br = k;

    int zb = again();

    for(int i = 0; i < k; i++)
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
