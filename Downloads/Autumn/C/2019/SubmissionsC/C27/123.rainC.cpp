#include<iostream>
using namespace std;
struct rain
{
    int v;
    int uv;
} a[1000005];
int main()
{
unsigned long long sum=0;
int n,max1=0,max2=0,ind1,ind2,k;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i].v;
    if(a[i].v>max1)max2=max1,ind2=ind1,max1=a[i].v,ind1=i;
    else if(a[i].v>=max2)max2=a[i].v,ind2=i;

}
///cout<<max1<<" "<<max2<<" "<<ind1<<" "<<ind2<<endl;
sum+=max2*(ind2-ind1);
if(ind1>ind2){swap(ind1,ind2);swap(max1,max2);}
cin>>k;
for(int i=0;i<k;i++)
{
int ind,b;
cin>>ind>>b;
a[ind].uv=b;
}
int br=0;
if(a[ind1].v+a[ind1].uv<a[ind2].v+a[ind2].uv)sum+=a[ind1].uv,br+=a[ind1].uv;
else sum+=a[ind2].uv,br+=a[ind2].uv;
for(int i=0;i<ind1;i++)
{
 if(a[i].v+a[i].uv<a[i+1].v+a[i+1].uv)sum+=a[i].v+a[i].uv,br+=a[i].uv;
 else sum+=a[i+1].v+a[i+1].uv,br+=a[i+1].uv;
}
for(int i=ind2+1;i<n;i++)
{
    if(a[i].v+a[i].uv<a[i-1].v+a[i-1].uv)sum+=a[i].v+a[i].uv,br+=a[i].uv;
    else sum+=a[i-1].v+a[i-1].uv,br+=a[i-1].uv;
}
cout<<br<<" "<<sum<<endl;
}
/**
6
2 4 2 4 2 1
2
2 1
4 1
*/
