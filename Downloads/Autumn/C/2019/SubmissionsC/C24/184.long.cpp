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
    int l1=s1.size(), l2=s2.size();
    if(l1<l2) return 0;
    int i=0, tb=0;
    while(i<l1 && tb<l2)
    {
        while(i<l1 && s1[i]!=s2[tb]) i++;
        if(i<l1) tb++;
        else break;
    }
    if(tb==l2) return 1;
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
    if(!maxbr) cout<<0<<endl;
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

5 7 3
fagcbdaga
dcdbf
acfebdc
cfc
cegdb

5 7 3
abcde
cd
abef
cdfga
hhegf

*/
