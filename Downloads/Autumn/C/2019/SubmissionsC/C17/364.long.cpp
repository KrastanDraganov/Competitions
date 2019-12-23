#include<iostream>
using namespace std;
string s[10000];
int sreshtaniq[30];
int main ()
{
    long long n,m,k;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int a=0; a<s[j].size(); a++)
            {
                if(s[j][a]=='a'+i)
                {
                    sreshtaniq[i]++;
                    break;
                }
            }
        }
    }
    int brvar=0;
    int brsr=0;
    int bukva;
    for(int i=0; i<n; i++)
    {
        if(sreshtaniq[i]>brsr){
            bukva=i;
            brsr=sreshtaniq[i];
        }
    }
    for(int i=0; i<n; i++)
    {
        if(sreshtaniq[i]==brsr)
        {
            brvar++;
        }
    }
    if(brsr==1){
        cout<<0<<"\n";
        return 0;
    }
    cout<<brsr<<"\n"<<char('a'+bukva)<<"\n"<<brvar<<"\n";
    return 0;
}
