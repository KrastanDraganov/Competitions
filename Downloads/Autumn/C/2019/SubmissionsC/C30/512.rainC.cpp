#include<iostream>
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long m[1000009],uv[1000009],d[1000009],m1[1000009][2],m2[1000009][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
   // memset(m1,-1,sizeof(m1));
    //memset(m2,-1,sizeof(m2));
    long long i,n,k,b,a,j,ma,ob=0,br=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>m[i];
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>a>>b;
        uv[a]=b;
        d[i]=a;
    }ma=0;
    for(i=0;i<n;i++)
    {
        
        m1[i][0]=ma;
        if(i-1!=0&&ma==m[i-1]&&m1[i][1]==0)m1[i][1]=i-1;
        else m1[i][1]=m1[i-1][1];ma=max(ma,m[i]);
    }ma=0;
    for(i=n-1;i>=0;i--)
    {
      ma=max(ma,m[i+1]);
      m2[i][0]=ma;
         if(i+1!=n-1&&ma==m[i+1]&&m2[i][1]==0)m2[i][1]=i+1;
        else m2[i][1]=m2[i+1][1];  
    }
     
    for(j=0;j<k;j++)
    {
        i=d[j];
        if((i!=n-1&&uv[i]+m[i]<=m1[i][0])&&(i!=0&&uv[i]+m[i]<=m2[i][0])){continue;}
        else if(i!=n-1&&uv[i]+m[i]>m2[i][0]){br++;m[i]+=uv[i];
            for(int t=i;t<=m2[i][1];t++){if(m2[t][0])m2[t][0]=m[i];m2[t][1]=i;}}
        else if(i!=0&&uv[i]+m[i]>m1[i][0]){br++;m[i]+=uv[i];
            for(int t=i;t>=m1[i][1];t--){if(m1[t][0])m1[t][0]=m[i];m1[t][1]=i;}}
        
    } 
    long long z;
    for(i=0;i<n;i++)
    {
        
        ob+=(m2[i][1]-m1[i][1])*(min(m2[i][0],m1[i][0]));
      //  cout<<m1[i][1]<<" "<<m2[i][1]<<endl;
    }
    
  
    cout<<br<<" "<<ob<<endl;
    
}
/*
6
2 4 2 4 2 1
2
2 1 4 1
*/