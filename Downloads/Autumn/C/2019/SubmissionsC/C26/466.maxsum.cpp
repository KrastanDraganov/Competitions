#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100002],b[10000];
long long s=0;
int s1(int p)
{
    int maxs=0;
    for(int i=0;i<k;i++)
    {
        if(a[p+b[i]]>maxs)maxs=a[p+b[i]];
    }
    return maxs;
}
int s3(int p)
{
    int maxs=0;
    int ind=0;
    for(int i=0;i<k;i++)
    {
        if(a[p+b[i]]>maxs)ind=b[i];
    }
    return ind;
}
int s2(int q)
{
    int maxs=0;
    for(int i=0;i<k;i++)
    {
        if(a[q-b[i]]>maxs)maxs=a[q-b[i]];
    }
    return maxs;
}
int s4(int q)
{
    int maxs=0;
    int ind=0;
    for(int i=0;i<k;i++)
    {
        if(a[q-b[i]]>maxs)ind=b[i];
    }
    return ind;
}
void sum(int p,int q)
{
    if(s1(p)>s2(q)){p+=s3(p);s+=a[p];}
    else {q-=s4(q);s+=a[q];}
    if(q-p<=b[0]){cout<<s<<endl;exit(0);}
    sum(p,q);
}
int main()
{
cin>>n>>k;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
for(int i=0;i<k;i++)
{
cin>>b[i];
}
sort(b,b+k);
int pos1=0;
int pos2=n-1;
sum(pos1,pos2);
}
