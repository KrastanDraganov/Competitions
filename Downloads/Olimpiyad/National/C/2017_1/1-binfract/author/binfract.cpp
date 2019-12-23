//Task: binfract
//Author: Kinka Kirilowa-Lupanowa

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
void printBin(int x) 
{
  int p2 = 1;
  while (p2 * 2 <= x) p2 *= 2;
  while (p2 > 0)
   {
    cout << x / p2;
    x %= p2;
    p2 /= 2;
  }
}

int main() 
{
  int a;
  scanf("%d.",&a);
  printBin(a);
  cout << ".";

  string sb;
  cin >> sb;
  int b = atoi(sb.c_str());
  
  int p10 = 1;
  for (int i = 0; i < sb.size(); i++) p10 *= 10;
 

  vector<int> digits;
  map<int, int> steps;
  for (int step = 0;;step++) 
  {
    if (b==0 || steps.find(b) != steps.end()) 
      break;
    steps[b] = step;
    b *= 2;
    digits.push_back(b / p10);
    b %= p10;
  }
  
  if (b == 0) 
  {
    for (int i = 0; i < digits.size(); i++) 
      cout << digits[i];
    cout << endl;
    return 0;
  }

  int step = steps.find(b)->second;
  for (int i = 0; i < digits.size(); i++) 
  {
    if (i == step) cout << "(";
    cout << digits[i];
  }
  cout << ")" << endl;
  return 0;
}
