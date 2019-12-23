
//Author: Emil Kelevedjiev
#include<iostream>
#include<stack>
#include<map>
#include<string>
using namespace std;

int a,b;
stack<int>d;
map<int,int>m;
string p;

int main()
{
   string s;
   cin >> s;
   a=0;
   int i=0;
   while(s[i]!='.')
   {
     a=10*a+(int)(s[i]-'0');
     i++;
   }
   b=0;
   i++;
   int x=1;
   while(i<s.size())
   {
     if(s[i]=='0') x = 10*x;
     b=10*b+(int)(s[i]-'0');
     i++;
   }

  while(a>0)
  {
    d.push(a%2);
    a=a/2;
  }

  if(d.empty()) cout << "0";
  else
  while(!d.empty())
  {
      cout << d.top();
      d.pop();
  }
  cout << ".";

  int c=10;
  while(c<b) c=10*c;
  c = x*c;
  i=1;
  int i1=0;
  int i2=0;
  bool per=true;
  while(1)
  {
    b=2*b;
    if(b>=c)
     {
       p=p+'1';
       b=b-c;
     }
    else
      {
        p=p+'0';
      }
    if(b==0){per=false;break;}
    if(m.count(b)==0) m[b]=i;
    else
    {
     i1=m[b];
     i2=i;
     break;
    }
    i++;
  }

  if(!per) {cout<<p<< endl; return 0;}


  string ss (p,i1,i2-i1);


  p = p+ss;
  int j=0;
  while(1)
  {
    string s1(p,j,i2-i1);
    string s2(p,j+i2-i1,i2-i1);
    if(s1==s2) break;
    j++;
  }

  int k=0;
  while(1)
  {
    cout << p[k];
    k++;
    if(k==j) cout << "(";
    if(k==j+i2-i1)
     {cout << ")" << endl; break;}
  }
}
