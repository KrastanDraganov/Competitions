#include<iostream>
#include<cstdlib>
#include<map>
using namespace std;

typedef long long int INT;

string s;
int m;

map<string,INT> d;

INT f(string s)
{
  if(s=="") return 1;
  if(d.count(s)>0) return d[s];
  INT c=f(s.substr(1));
  if(s.size()>1)
  {
   string s2=s.substr(0,2);
   if(s2.size()==2)
   {
    int v=atoi(s2.c_str());
    if((10<=v)&&(v<=m))
     c=c+f(s.substr(2));
   }
  }
  d[s]=c;
  return c;
}

int main()
{
  cin >> m;
  m=9+m;
  cin >> s;
  INT r=f(s);
  cout << r << endl;
}
