#include<bits/stdc++.h>
using namespace std;
vector <int> a;
int s[1000];
int main()
{
int n,k,sum=0,sumk=0;
cin>>n>>k;
for(int i=0;i<n;i++)
{
    int b;
    cin>>b;
    a.push_back(b);
}
for(int i=0;i<k;i++)
{
    cin>>s[i];
    sumk+=s[i];
}
if(k==2)
{
    if(sumk>=n-1)
    {
        for(int i=0;i<2;i++)
        {
            int sum1=0,sum2=0;
            for(int j=0;j<n;j+=s[i])
            {
                sum1+=a[j];
            }
            for(int j=n-1;j>=0;j-=s[i])
            {
                sum2+=a[j];
            }
            if(sum1>sum||sum2>sum)sum=max(sum1,sum2);
        }
    }
}
cout<<sum<<endl;
return 0;
}
