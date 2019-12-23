#include<iostream>
#include<algorithm>
#include<string>
#define endl '\n'
using namespace std;
int b[100005][30];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,ma=0;
    char c;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        sort(s.begin(),s.end());
        b[i][s[0]]++;
        for(int j=1;j<s.size();j++)
        {
            if(s[j]>m+'a') break;
            if(s[j]!=s[j-1])
            b[i][s[j]-'a']++;
            if(ma==b[i][s[j]-'a']) ma++;
            if(ma<b[i][s[j]-'a']){ma=b[i][s[j]-'a'];c=s[j];}

        }
    }
    cout<<ma<<endl<<c<<endl<<1<<endl;

}
