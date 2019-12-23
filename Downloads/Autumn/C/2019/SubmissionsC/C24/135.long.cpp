#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int brtotal=0;
string razb[70000];
int brpyti[70000];
bool usedgen[26]={0};
int n, m, k;

void gen(string tek)
{
    if(tek.size()==k)
    {
        razb[brtotal]=tek;
        brtotal++;
        return;
    }
    for(int i=1; i<=m; i++)
    {
        if(!usedgen[i])
        {
            usedgen[i]=1;
            gen(tek+char(i+'a'-1));
            usedgen[i]=0;
        }
    }
}

bool syd(string s1, string s2)
{
    int i=0, tb=0;
    while(i<n && tb<s2.size())
    {
        while(i<n && s1[i]!=s2[tb]) i++;
        if(s1[i]==s2[tb]) tb++;
        else break;
    }
    if(tb==s2.size()) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    gen("");
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for(int j=0; j<brtotal; j++)
        {
            if(syd(s, razb[j])) brpyti[j]++;
        }
    }
    int maxbr=0, mq=0, rr=0;
    for(int i=0; i<brtotal; i++)
    {
        if(brpyti[i]>maxbr)
        {
            rr=1;
            mq=i;
            maxbr=brpyti[i];
        }
        else if(maxbr==brpyti[i]) rr++;
    }
    if(!rr) cout<<0<<endl;
    else
    {
        cout<<maxbr<<endl;
        cout<<razb[mq]<<endl;
        cout<<rr<<endl;
    }
    return 0;
}
/**
5 7 2
fagcbdaga
dcdbf
acfebdc
cfc
cegdb
*/
