#include<iostream>
using namespace std;

long long int a, b, c;

int main()
{
   cin >> a >> b >> c;

  long long int r=-2;
  for(int n=0;n<=a-1;n++)
  for(int m=0;m<=a*b-1;m++)
  if( (a*b-1)*n==(a-1)*m) r++;
  cout << r << endl;
}
