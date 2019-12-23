#include<iostream>
#include<cstdlib>
using namespace std;

string s;
int m;

int f(string s)
{
  if(s=="") return 1;
  int c=f(s.substr(1));
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
  return c;
}

int main()
{
  cin >> m;
  m=9+m;
  cin >> s;
  int r=f(s);
  cout << r << endl;
}
