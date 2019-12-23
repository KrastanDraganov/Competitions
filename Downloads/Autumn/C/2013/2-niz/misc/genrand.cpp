#include<iostream>
using namespace std;

int n=100;

int main()
{
  srand(time(0));
  string s;
  for(int i=0;i<n;i++) s = s + char(int('0')+(rand()%100<1?1:0));
  
  cout << s << endl;    
    
}
