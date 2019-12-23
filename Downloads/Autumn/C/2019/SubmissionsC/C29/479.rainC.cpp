#include<iostream>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,pr,h,k,mh=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;

    }
    cin>>k;

    for(int i=0;i<k;i++)
    {
        cin>>pr>>h;
        mh=max(mh,h);
    }
    cout<<1<<" "<<mh<<endl;

}

