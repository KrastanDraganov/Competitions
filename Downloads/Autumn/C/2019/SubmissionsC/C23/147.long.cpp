#include<bits/stdc++.h>
using namespace std;
string s[10000];
int t[10000][30];
char c;
int main()
{
int n,m,k,br2=0,brmax=0;
cin>>n>>m>>k;
for(int i=0;i<n;i++)
{
    cin>>s[i];
    for(int j=0;j<s[i].size();j++)
    {
        t[i][s[i][j]-'a']++;
    }
}
for(int i=0;i<27;i++)
{
    int br=0;
    for(int j=0;j<n;j++)
    {
        if(t[j][i])br++;
    }
    if(br>brmax){brmax=br;c=i+'a';}
    if(br)br2++;
}
cout<<brmax<<endl<<c<<endl<<br2<<endl;
}
