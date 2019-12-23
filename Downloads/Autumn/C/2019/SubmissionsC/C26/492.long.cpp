#include<bits/stdc++.h>
using namespace std;
int n,k,m,maxl=0;
string p[10002][100];
string st[10002];
int a=0;
int br[1000002]={0};
vector<string>subs;
vector<string>subs1;
string str;
int brmax=0,brm=0;
void rec(string s,string t,vector<string>&a,int d,int mb)
{
    for(int i=d+1;i<s.size();i++)
    {
        t=t+s[i];
        if(t.size()<mb)rec(s,t,a,i,mb);
        if(t.size()==mb){a.push_back(t);return;}
        if(i==s.size())return;
    }
}
int main()
{
cin>>n>>m>>k;
for(int i=0;i<n;i++)
{
    cin>>st[i];
    if(st[i].size()>maxl)maxl=st[i].size();
    int q=st[i].size()-k;
    for(int j=0;j<=q;j++)
    {
        int y=0;
        string h="";
        rec(st[i],h,subs,j,k);
        for(int z=a;z<subs.size();z++)
        {
            p[i][y]=subs[a];
            y++;
        }
        a=subs.size();
    }
}
//sort(subs,subs+a);
for(int i=1;i<subs.size();i++)
{
    if(subs[i].size()!=subs[i-1].size())subs1.push_back(subs[i-1]);
    else if(subs[i]!=subs[i-1])subs1.push_back(subs[i-1]);
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<maxl;j++)
    {
        for(int x=0;x<subs1.size();x++)
        {
            if(p[i][j]==subs1[x])br[x]++;
        }
    }
}
for(int i=0;i<subs1.size();i++)
{
    if(br[i]>brmax){brmax=br[i];str=subs1[i];brm=1;}
    else if(br[i]==brmax)brm++;
}
cout<<brmax<<endl;
cout<<str<<endl;
cout<<brm<<endl;
}
/*
5 7 2
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
*/
/*
2
dc
6
*/
