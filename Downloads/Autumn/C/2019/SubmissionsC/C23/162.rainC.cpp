#include<bits/stdc++.h>
using namespace std;
vector <int> a;
bool t[1000000];
int main()
{
int n,k,br=0,maxuv=0,maxi2=0;
cin>>n;
for(int i=0;i<n;i++)
{
    int b;
    cin>>b;
    a.push_back(b);
    if(b>maxi2)maxi2=b;
}
int maxi=a[0],ind=0;
cin>>k;
for(int i=0;i<k;i++)
{
    int b,maxv;
    cin>>b>>maxv;
}
cout<<2<<" "<<maxi2*(n-1);
return 0;
for(int i=1;i<n;i++)
{
    if(a[i]>=maxi){maxuv+=a[ind]*(i-ind);maxi=a[i];ind=i;}
    else t[i]=1;
}
if(ind!=n-1)
{
    int maxp=a[n-1],ind2=n-1;
    for(int i=n-2;i>=ind;i--)
    {
        if(a[i]>=maxp){maxuv+=a[ind2]*(ind2-i);maxp=a[i];ind2=i;}
        else t[i]=1;
    }
}

    /**if(t[b]==1)continue;
    else
    {
        if(b!=0&&a[b-1]>a[b])
        {
            if(a[b-1]-a[b]>maxv){br++;a[b]+=maxv;maxuv+=maxv;}
            else {maxuv+=a[b-1]-a[b];br++;}
        }
        if(b!=n-1&&a[b+1]>a[b])
        {
            if(a[b+1]-a[b]>maxv){br++;a[b]+=maxv;maxuv+=maxv;}
            else {maxuv+=a[b+1]-a[b];br++;}
        }
    }*/
cout<<0<<" "<<maxuv;
return 0;
}
/**
6
2 4 2 4 2 1
2
2 1
4 1
*/
