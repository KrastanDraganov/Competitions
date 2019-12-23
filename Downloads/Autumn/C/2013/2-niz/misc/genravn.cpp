#include<iostream>
using namespace std;

string s[1000000];

void rhythm(int k, int m, string s[])
{
  int n=k+m;
  for(int i=1;i<=k;i++) s[i]="1";
  for(int i=k+1;i<=n;i++) s[i]="0";
  int d=min(k,m);
  while(d>0)
  {
    int c=k+m;
    for(int i=1;i<=d;i++)
     {s[i]=s[i]+s[c]; s[c]=""; c--;}
    if(k>m) k=k-m; else m=m-k;
    d=min(k,m);
  }
}


int main()
{
  rhythm(121393, 190000 ,s);
  
 // cout << s[1].size()<< endl;
  cout << s[1];
  
  //system("pause");  
      
    
    
}
