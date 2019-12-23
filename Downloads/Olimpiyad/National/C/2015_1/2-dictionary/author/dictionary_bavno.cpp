#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
string s, words[2010];
int n, m, ans[2010], br, minbr, rans[2010];

void Copy()
{
    for (int i=1; i<=minbr; i++)
   {
       rans[i]=ans[i];
   }
}

bool Less()
{
    for (int i=1; i<=minbr; i++)
        if (ans[i]<rans[i]) return true;
    return false;
}

void rec(int pos)
{
    if (pos>m) return;
    if (pos==m)
    {
        if (br<minbr)
        {
            minbr=br;
            Copy();
        }
        else
            if (br==minbr && Less()) Copy();
        return;
    }
    for (int i=1; i<=n; i++)
    {
        if (s.substr(pos,words[i].size())==words[i])
        {
            br++;
            ans[br]=pos+words[i].size();
            rec(pos+words[i].size());
            br--;
        }
    }
}
int main()
{
    cin>>s;
    m=s.size();
    minbr=m+1;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>words[i];
    rec(0);
    for (int i=minbr-1; i>=1; i--)
        s.insert(rans[i]," ");
    cout<<minbr<<endl;
    cout<<s<<endl;
    return 0;
}
