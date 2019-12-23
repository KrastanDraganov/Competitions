#include<iostream>
using namespace std;

bool check(string s, int& m1, int& m2)
{
  m1=s.size()+1;
  m2=0;
  
  if(s=="") return false;
  
  if(s[0]=='0') return false;
  
  for(int i=1;i<s.size();i++)
   if((s[i-1]=='1')&&(s[i]=='1')) return false;
  
  int c=0;
  for(int i=0;i<s.size();i++)     
   if(s[i]=='1') c++;
  if(2*c>s.size()) return false;
  
  int d=0;
  for(int i=0;i<s.size();i++)
  {
   if(s[i]=='1')
    { if(d>m2) m2=d;
      if(d!=0)if(d<m1) m1=d;
      d=0;
    }
   else d++;
  }  
  if(d>m2) m2=d;
  if(d!=0)if(d<m1) m1=d;
  cout << m1 << " " << m2 << endl;
  if(m2-m1>1) return false;
  return true;
}

string reduc(string s, int m1, int m2)
{
  int c1=0;
  int c2=0;
  int d=0;
  for(int i=0;i<s.size();i++)
  {
   if(s[i]=='1')
    { if(d!=0) 
       {
         if(d==m1) c1++; else c2++;
       }
      d=0;
    }
   else d++;
  }  
  if(d!=0)
   {if(d==m1) c1++; else c2++;}
   
  cout << "c1=" << c1 << " c2=" << c2 << endl;
  
  char v1='1';
  char v2='0';

  if(m1<m2)
  {
  if(c1<c2){v1='1';v2='0';}
  else if(c1>c2){v1='0';v2='1';}
  }
  else {v1='0'; v2='0';}
  
  string r="";
  d=0;
  for(int i=0;i<s.size();i++)
  {
   if(s[i]=='1')
    { if(d!=0) 
       {
         if(d==m2) r = r + v2; else r = r + v1;
       }
      d=0;
    }
   else d++;
  }  
  if(d!=0)
   {if(d==m2) r = r + v2; else r = r + v1;}
  
  if(r.find("1")!=string::npos)
  while(r[0]!='1') r = r.substr(1) + r.substr(0,1);
  
  return r; 
}

int main()
{
  string s,r;
  cin >> s;
  cout << s << endl;
  int c=0;
  int m1,m2;
  while(check(s,m1,m2))
  { c++;
    cout << "m1=" << m1 << " m2=" << m2 << endl;
    r=reduc(s,m1,m2);
    cout << r << endl;
    s=r;
  }
  
  cout << c << " " << s.substr(0,50) << endl;
  //system("pause");
    
}
