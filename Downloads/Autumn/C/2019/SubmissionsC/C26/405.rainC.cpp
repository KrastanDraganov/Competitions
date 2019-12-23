#include<bits/stdc++.h>
using namespace std;
int n,k;
int pr[1000002];
int prp[1000002],pl[1000002];
int brt=0;
int s=0;
int main()
{
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>pr[i];
}
cin>>k;
for(int i=0;i<k;i++)
{
    int br=0;
    cin>>prp[i]>>pl[i];
    for(int j=prp[i]-1;j>=0;j--)
    {
        if(pr[j]>pr[prp[i]]){br++;break;}
    }
    for(int j=prp[i]+1;j<n;j++)
    {
        if(pr[j]>pr[prp[i]]){br++;break;}
    }
    if(br==1){pr[prp[i]]+=pl[i];brt++;}
}
for(int i=0;i<n;i++)cout<<pr[i]<<" ";
int i=0;
while(i<n-1)
{
    int maxp=0,fl=0,p=0;
    for(int j=i+1;j<n;j++)
    {
        if(pr[j]>=pr[i]){s+=(j-i)*pr[i];i=j;fl=1;break;}
        else if(pr[j]>maxp){maxp=pr[j];p=j;}
    }
    if(!fl){s+=(p-i)*maxp;i=p;}
}
cout<<brt<<" "<<s<<endl;
}
