#include<iostream>

using namespace std;

int a[100005];

int b[1005];

int n,k;

int maxx = 0;

void recursion(int indx1, int indx2, int zb)
{
    if(zb > maxx)
    {
        maxx = zb;
    }

    for(int i = 0;i < k;i++)
    {
        if(indx1 + b[i] < indx2)
        {
            recursion(indx1 + b[i],indx2,zb + a[indx1 + b[i]]);
        }
    }

    for(int i = 0;i < k;i++)
    {
        if(indx2 - b[i] > indx1)
        {
            recursion(indx1,indx2 - b[i],zb + a[indx2 - b[i]]);
        }
    }

    return;
}

int main()
{
    cin>>n>>k;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }

    for(int i = 0;i < k;i++)
    {
        cin>>b[i];
    }

    recursion(0,n - 1,a[0] + a[n - 1]);

    cout<<maxx<<endl;
}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2

6 2
1 4 7 2 5 1
3 4
*/
