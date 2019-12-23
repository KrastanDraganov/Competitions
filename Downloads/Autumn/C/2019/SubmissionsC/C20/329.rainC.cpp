#include<bits/stdc++.h>
using namespace std;
struct dx
{
 long long leftbig=0;
 long long diff1;
 long long rightbig=0;
 long long diff2;
}borders[1000002];
long long n,len[1000002],k,a,b,v=0,maxl=0,jj=1,br=0;
bool fl=0;
int main()
{
 cin>>n;
 for(int i=0;i<n;i++)cin>>len[i];
 for(int i=0;i<n-1;i++)
 {
  for(int j=i+1;j<=n;j++)
  {
   if(len[i]<=len[j]){maxl=len[i];jj=j-i;break;}
   else if(len[j]>maxl){maxl=len[j];jj=j-i;}
  }
  if(jj>1)i+=jj-1;

  v+=maxl*jj;
  maxl=0;
  jj=1;
 }

 for(int i=0;i<n-1;i++)
 for(int j=i+1;j<n;j++)
 if(len[j]>borders[i].rightbig){borders[i].rightbig=len[j];borders[i].diff2=abs(j-i);}

 for(int i=n;i>0;i--)
 for(int j=i-1;j>=0;j--)
 if(len[j]>borders[i].leftbig){borders[i].leftbig=len[j];borders[i].diff1=abs(j-i);}
 cin>>k;
 for(int i=0;i<k;i++)cin>>a>>b;
 cout<<0<<" "<<v<<endl;
 return 0;
}
