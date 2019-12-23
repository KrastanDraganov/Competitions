#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
stack <int> s;
int i,j,p,q,n,m,k,a[1000001],b[1000001],sum,br,max1;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(i=n; i>=1; i--)
    {
        while(!s.empty() && a[s.top()]<a[i])
        {
            //cout<<a[s.top()]<<" "<<a[i]<<endl;
            s.pop();
        }
        if(s.empty())b[i]=0;
        else b[i]=s.top();
        s.push(i);
        //cout<<b[i]<<" ";
    }
    i=1;
    while(i<=n)
    {
        //cout<<p<<endl;
        if(b[i]>0)
        {
            //cout<<b[i]<<" "<<i<<" "<<a[i]<<endl;
            sum+=(b[i]-i)*a[i];
            i=b[i];
        }
        else sum+=a[i+1],i++;
    }
    max1=sum;
    //cout<<p<<endl;
    cin>>m;
    for(i=1; i<=m; i++)
    {
        scanf("%d%d",&p,&q);
        p++;
        a[p]+=q;
        sum=0;
        fill(b+1,b+n+1,0);
        while(!s.empty())s.pop();
        for(j=n; j>=1; j--)
        {
            while(!s.empty() && a[s.top()]<a[j])
            {
                //cout<<a[s.top()]<<" "<<a[i]<<endl;
                s.pop();
            }
            if(s.empty())b[j]=0;
            else b[j]=s.top();
            s.push(j);
           // cout<<b[j]<<" ";
        }
        j=1;
        while(j<=n)
        {
            //cout<<p<<endl;
            if(b[j]>0)
            {
                //cout<<b[i]<<" "<<i<<" "<<a[i]<<endl;
                sum+=(b[j]-j)*a[j];
                j=b[j];
            }
            else sum+=a[j+1],j++;
        }
        if(sum>max1)
        {
            max1=sum;
            br++;
        }
    }
    cout<<br<<" "<<max1<<endl;
    return 0;
}
/**
6
2 4 2 4 2 1
2
2 1
4 1
*/
