#include<iostream>
#define endl '\n'
using namespace std;
long long m1[1000009],m2[1000009],m[1000009],p[100008];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    m1[0]=m[0];m1[n-1]=m[n-1];
    m2[0]=m[0];m2[n-1]=m[n-1];
    for(i=0;i<k;i++)cin>>p[i];
    
    for(i=1;i<n-1;i++)
    {
        long long ma=-9999999;
       // bool h=false;
        for(long long j=0;j<k;j++)
        {
            if(i>p[j]-1){ma=max(ma,m1[i-p[j]]);}
        }
        if(ma!=-9999999)m1[i]=ma+m[i];
        //else m1[i]=-1;
    }
     for(i=n-1;i>0;i--)
    {
        long long ma=-999999;
        for(long long j=0;j<k;j++)
        {
            if(n-i>p[j]-1){ma=max(ma,m2[i+p[j]]);}
        }
        if(ma!=-999999)m2[i]=ma+m[i];
       // else m2[i]=-1;
    }long long ms=m1[0];
    for(i=1;i<n-1;i++)
    {
        ms=max(ms,m1[i]);
        m1[i]=ms;
    }ms=m2[n-1];
    for(i=n-2;i>=1;i--){
        ms=max(ms,m2[i]);
        m2[i]=ms;
    }
    //for(i=0;i<n;i++)cout<<m1[i]<<" "<<m2[i]<<endl;
    long long mi=-999999;
    for(i=0;i<n-1;i++)
    {
        mi=max(mi,m1[i]+m2[i+1]);
    }
    cout<<mi<<endl;
    
}

/*
9 2
3 2 6 6 0 2 4 5 5
3 2

6 2
1 4 7 2 5 1
3 4
*/