#include<iostream>
#define endl '\n'
using namespace std;
int m[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,pr,h,k,mh=0,in=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
    }
    cin>>k;

    for(int i=0;i<k;i++)
    {
        cin>>pr>>h;
        mh=max(mh,h);
        if(mh==h)in=pr;
    }
    cout<<1<<" "<<m[pr-1]-m[pr]<<endl;

}

