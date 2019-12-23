#include<iostream>
#include<string>
#include<map>
using namespace std;
int n,m,k,i,j,p,q,d,a[31],max1,br=1,j1,j2,p1,a1[2001],g;
string s[10001],f,f1,f2;
bool b[30],fl,b1[2001],b2[200001];
int main()
{
    cin>>n>>m>>k;
    for(i=1; i<=n; i++)
    {
        cin>>s[i];
        fill(b+1,b+27+1,0);
        d=s[i].size()-1;
        if(k==1)
        {
            for(j=0; j<=d; j++)
            {
                p=s[i][j]-'a'+1;
                if(!b[p])
                {
                    a[p]++;
                    b[p]=1;
                }
            }
        }
        if(k==2)
        {
            fill(b1+1,b1+2000+1,0);
            for(j=0; j<=d; j++)
            {
                for(j1=j+1; j1<=d; j1++)
                {
                    p=s[i][j]-'a'+1;
                    q=s[i][j1]-'a'+1;
                    if(!b1[p*100+q])
                    {
                        b1[p*100+q]=1;
                        a1[p*100+q]++;
                        //cout<<p*100+q<<endl;
                    }
                }
            }
        }
        /*if(k==3)
        {
            map <string,bool> mb;
            for(j=0; j<=d; j++)
            {
                for(j1=j+1; j1<=d; j1++)
                {
                    for(j2=j1+1; j2<=d; j2++)
                    {

                        f="";
                        f=f+s[i][j]+s[i][j1]+s[i][j2];
                        //cout<<f<<endl;
                        if(!mb[f])
                        {

                            mb[f]=1;
                            ma[f]++;
                        }
                    }
                }
            }
        }
        */
    }
    if(k==1)
    {
        for(i=1; i<=26; i++)
        {
            //cout<<a[i]<<" ";
            if(a[i]>max1)max1=a[i];
        }
        cout<<max1<<endl;
        for(i=1; i<=26; i++)
        {
            if(a[i]==max1 && fl==1)br++;
            if(a[i]==max1 && fl==0)
            {
                cout<<char(i+'a'-1)<<endl;
                fl=1;
            }
        }
        cout<<br;
    }
    else if(k==2)
    {
        //cout<<a1[602]<<"ans"<<endl;
        max1=0;
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=m; j++)
            {
                f="";
                p=char(i+'a'-1);
                q=char(j+'a'-1);
                g=0;
                g=i*100+j;
                cout<<g<<endl;
                if(a1[g]>max1)max1=a1[g];
            }
        }
        cout<<max1<<endl;
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=m; j++)
            {
                f="";
                char p1=char(i+'a'-1);
                char q1=char(j+'a'-1);
                g=0;
                g=i*100+j;
                if(a1[g]==max1)
                {
                   // cout<<f<<endl;
                    br++;
                }
                if(a1[g]==max1 && !fl)
                {
                    cout<<p1<<""<<q1<<endl;
                    fl=1;
                }
            }
        }
        cout<<br-1;
    }
    /*else if(k==3)
    {
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=m; j++)
            {
                for(j1=1; j1<=m; j1++)
                {
                    f="";
                    p=char(i+'a'-1);
                    q=char(j+'a'-1);
                    p1=char(j1+'a'-1);
                    f=p;
                    f1=q;
                    f2=p1;
                    f=f+f1+f2;
                    if(ma[f]>max1)max1=ma[f];
                }
            }
        }
        cout<<max1<<endl;
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=m; j++)
            {
                for(j1=1; j1<=m; j1++)
                {
                    f="";
                    p=char(i+'a'-1);
                    q=char(j+'a'-1);
                    p1=char(j1+'a'-1);
                    f=p;
                    f1=q;
                    f2=p1;
                    f=f+f1+f2;
                    if(ma[f]==max1)
                    {
                        //cout<<f<<endl;
                        br++;
                    }
                    if(ma[f]==max1 && !fl)
                    {
                        cout<<f<<endl;
                        fl=1;
                    }
                }
            }
        }
        cout<<br-1;
    }*/
    else
    {
        cout<<0;
    }
    return 0;
}
/**
5 26 2
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
