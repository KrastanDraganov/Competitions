#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct bak
{
    string bu;
    int br=0;
};

bool cmp(bak x,bak y)
{
    if (x.br>y.br) return true;
    if (y.br>x.br) return false;
    if (y.br==x.br)
    {
        if (x.bu[0]>y.bu[0]) return false;
        if (y.bu[0]>x.bu[0]) return true;
    }
}
bak buk[27];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    string nis;
    for (int i=0;i<n;i++)
    {
        cin>>nis;
        for (int j=0;j<nis.size();j++)
        {
            if (nis[j]==buk[(nis[j]-'a')+1].bu) buk[(nis[j]-'a')+1].br++;
            else {buk[(nis[j]-'a')+1].bu = nis[j];buk[(nis[j]-'a')+1].br++;}
        }
    }
    sort (buk,buk+27,cmp);
    cout<<buk[0].br<<endl;
    cout<<buk[0].bu<<endl;
    int sr=buk[0].br,brr=1;
    for (int i=1; ;i++)
    {
        if (buk[i].br==sr) brr++;
        else break;
    }
    cout<<brr<<endl;
    return 0;
}
/*
5 7 1
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
*/
