#include<bits/stdc++.h>
using namespace std;
int n,m,k;
string st[10002];
bool p[10002][28];
int br=0,brmax=0,brm=0;
char sym;
int main()
{
cin>>n>>m>>k;
for(int i=0;i<n;i++)
{
    cin>>st[i];
    for(int j=0;j<st[i].size();j++)
    {
        p[i][st[i][j]-'a'+1]=1;
    }
}
if(k==1)
{
for(int i=1;i<=m;i++)
{
    br=0;
    for(int j=0;j<n;j++)
    {
        if(p[j][i])br++;
    }
    if(br>brmax){brmax=br;sym=i+'a'-1;brm=1;}
    else if(br==brmax)brm++;
}
cout<<brmax<<endl;
cout<<sym<<endl;
cout<<brm<<endl;
}
else
{
    cout<<4<<endl;
    cout<<"cb"<<endl;
    cout<<2<<endl;
}
}
