#include<iostream>
#include<string>
using namespace std;
int n,m,k,i,j,p,q,d,a[31],max1,br=1;
string s[10001];
bool b[30],fl;
int main()
{
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
        fill(b+1,b+27+1,0);
        d=s[i].size()-1;
        for(j=0;j<=d;j++)
        {
            p=s[i][j]-'a'+1;
            if(!b[p])
            {
                a[p]++;
                b[p]=1;
            }
        }
    }
    if(k==1)
    {
    for(i=1;i<=26;i++)
    {
        //cout<<a[i]<<" ";
        if(a[i]>max1)max1=a[i];
    }
    cout<<max1<<endl;
    for(i=1;i<=26;i++)
    {
        if(a[i]==max1 && fl==1)br++;
        if(a[i]==max1 && fl==0){cout<<char(i+'a'-1)<<endl;fl=1;}
    }
    cout<<br;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
/**
5 26 1
fagcbdaga
dcdfb
acfebdc
cfc
cegdb

5 26 1
a
b
c
d
e
*/
