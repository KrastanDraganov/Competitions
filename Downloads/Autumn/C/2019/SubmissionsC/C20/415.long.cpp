#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,m,k,letter[27]={},maxx=0,br=0;
 bool nn[27]={};
 string a;
 char b;
 cin>>n>>m>>k;
 for(int i=0;i<n;i++){
 cin>>a;
 for(int j=0;j<a.size();j++){if(!nn[a[j]-'a'])letter[a[j]-'a']++;nn[a[j]-'a']=1;}
 for(int d=0;d<27;d++)nn[d]=0;
 }
 for(int i=0;i<27;i++)
    {
        if(letter[i]>maxx){maxx=letter[i];b=i+'a';}
        else if(letter[i]==maxx)br++;
 }
 cout<<1<<endl;
 cout<<b<<endl;
 cout<<br+1<<endl;
 return 0;
}
/*
5 7 2
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
*/
