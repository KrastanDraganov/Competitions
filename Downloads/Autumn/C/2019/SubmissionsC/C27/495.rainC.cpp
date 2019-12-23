#include<iostream>
#include<algorithm>
using namespace std;
struct ograda
{
    int vis;
    int ind;
    int dop;
}a[1000005];
bool cmp(ograda p,ograda q)
{
    if(p.vis==q.vis)return p.ind<q.dop;
    return p.vis>q.vis;
}
int main()
{
    unsigned long long sum=0,br=0;
int n,in,k,ch;
cin>>n;
for(int i=0;i<n;i++)cin>>a[i].vis;
cin>>k;
for(int i=0;i<k;i++)cin>>in>>ch,a[in].dop=ch,a[in].vis+=ch;
for(int i=0;i<n;i++)a[i].ind=i;
sort(a,a+n,cmp);
for(int i=0;i<n;i++)
{
    if(a[i].vis==0)continue;
    int j=i+1;
    int brr=1;
    int p=i+1;
    while(a[i].vis==a[p].vis)brr++,p++;
    if(brr>2)j+=brr-2;
    ///cout<<"j= "<<j<<endl;
    sum+=a[j].vis*(j-i);
    int i2=min(a[i].ind,a[j].ind);
    int j2=max(a[i].ind,a[j].ind);
    for(int t=i;t<n;t++){if(a[t].ind>i2&&a[t].ind<j2)a[t].vis=0;}
    ///for(int i=0;i<n;i++)cout<<a[i].vis<<" "<<a[i].ind<<" "<<a[i].dop<<endl;
    ///cout<<endl;
}
for(int i=0;i<n;i++)if(a[i].vis!=0)br+=a[i].dop;
cout<<br<<" "<<sum<<endl;
}
/**
7
1 2 3 4 3 2 1
7
0 1
1 2
2 3
3 4
4 5
5 6
6 7
*/
