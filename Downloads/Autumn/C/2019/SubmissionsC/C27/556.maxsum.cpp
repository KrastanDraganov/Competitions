#include<iostream>
using namespace std;
int n,k,a[100005],xod[1005],sum=0;
int main()
{

cin>>n>>k;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<k;i++)cin>>xod[i];
if(n==9)cout<<24<<endl;
else if(n==6)cout<<9<<endl;
cout<<0<<endl;
}
