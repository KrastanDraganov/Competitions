#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[100000],h[100000];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<k;i++)
    {
        cin>>h[i];
    }
    sort(h,h+k);
    int p1=0,p2=n-1,maxi1,maxi2,z,x,sr=-1,sum=a[p1]+a[p2];
    vector<int> sumh;
    while (true)
    {
        for (int i=0;i<k;i++)
        {
            if (p1+h[i]>=p2) continue;
            sumh.push_back(a[p1+h[i]]);
        }
        if (sumh.size()==0) break;
        for (int i=0;i<sumh.size();i++)
        {
            //cout<<"sumh="<<sumh[i]<<endl;
            if (sumh[i]>sr) {x=i;sr=sumh[i];}
        }
        maxi1=sr;
        //cout<<"maxi1= "<<maxi1<<endl;
        sumh.clear();
        sr=-1;

        for (int i=0;i<k;i++)
        {
            if (p2-h[i]<=p1) continue;
            sumh.push_back(a[p2-h[i]]);
        }
        if (sumh.size()==0) break;
        for (int i=0;i<sumh.size();i++)
        {
            //cout<<"sumh="<<sumh[i]<<endl;
            if (sumh[i]>sr) {z=i;sr=sumh[i];}
        }
        maxi2=sr;
        //cout<<"maxi2= "<<maxi2<<endl;
        sumh.clear();
        sr=-1;

        if (maxi1>maxi2) {sum=sum+maxi1;p1=p1+h[x];}
        else {sum=sum+maxi2;p2=p2-h[z];}
        //cout<<"sum="<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2
*/
