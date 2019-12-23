#include <iostream>
#include <string>
using namespace std;

string s,sr;

int main()
{
 cin >> s;
 int L=s.length();
 for(int i=0;i<L;i++) sr += s[L-i-1];
 for(int i=0;i<L;i++)
  if (s[i]==s[L-1])
    if(s.substr(i,(L-i)/2)==sr.substr(0,(L-i)/2))
     {cout << i << endl; break;}
}
