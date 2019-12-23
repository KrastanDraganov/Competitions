#include<bits/stdc++.h>
using namespace std;
int t[10000][30];
int mini[10000][30],maxi[10000][30];
string s[10000];
string res;
char c;
int main()
{
    int n,m,k,br2=0,brmax=0,br3=0;
    cin>>n>>m>>k;
    memset(mini,-1,sizeof(mini));
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        for(int j=0; j<s[i].size(); j++)
        {
            t[i][s[i][j]-'a']++;
            if(j>maxi[i][s[i][j]-'a'])maxi[i][s[i][j]-'a']=j;
            if(j<mini[i][s[i][j]-'a']||mini[i][s[i][j]-'a']==-1)mini[i][s[i][j]-'a']=j;
        }
    }
        for(int i=0; i<27; i++)
        {
            int br=0;
            for(int j=0; j<n; j++)
            {
                if(t[j][i])br++;
            }
            if(br>brmax)
            {
                brmax=br;
                res=char(i+'a');
                c=i+'a';
            }
        }
    int brmax2=0;
    for(int p=1; p<k; p++)
    {
        for(int i=0; i<27; i++)
        {
                int br=0;
                if(i+'a'==c)continue;
                for(int r=0; r<n; r++)
                {
                    for(int d=mini[r][c-'a']; d<s[r].size(); d++)
                    {
                        if(s[r][d]==char(i+'a'))
                        {
                            br++;
                            break;
                        }
                    }
                }
                if(br>brmax2&&res.size()==p)
                {
                    brmax2=br;
                    res=res+char(i+'a');
                    br2++;

                }
                else if(br>brmax2&&res.size()==p+1)
                {
                    brmax2=br;
                    res[p]=char(i+'a');
                }
                else if(br==brmax2&&p==k-1)br2++;
                if(i==26){c=res[p];brmax=brmax2;brmax2=0;br3=br2;br2=0;}
        }
    }
    if(br3&&brmax!=1)cout<<brmax<<endl<<res<<endl<<br3<<endl;
    else cout<<0<<endl;
    return 0;
}
/**
5 7 2
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
*/
