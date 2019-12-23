#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <ctime>
#define TESTS 25


using namespace std;
int A[TESTS][5] = {
{10000, 1000, 1, 1, 1},
{10000, 10, 1400, 700, 700},
{1, 2000, 1, 1, 1},
{1000, 1000, 1000, 1000, 1000},
{1000, 1000, 16, 5, 6},
{10, 85, 3, 1, 3},
{60, 502, 4, 4, 3},
{4513, 1609, 10, 5, 10},///
{160, 843, 6, 4, 5},
{210, 48, 1, 1, 1},
{260, 123, 3, 3, 1},
{2471, 367, 28, 14, 24},///
{8415, 329, 6, 6, 2},///
{410, 638, 6, 5, 1},
{460, 103, 3, 3, 2},
{1001, 176, 6, 5, 2},
{3509, 751, 8, 3, 6},
{6017, 376, 6, 4, 5},
{8525, 10, 8, 7, 7},
{1103, 1516, 7, 2, 1},
{1351, 1247, 5, 3, 1},
{1609, 1542, 8, 2, 1},
{1857, 353, 6, 6, 4},
{2165, 1719, 2, 2, 1},
{2373, 1687, 9, 1, 6}
};



int main(){

  char namein[100], exename[200];
  ofstream fin;
  unsigned long long a, b, p, q, i, j, k;

  for (int i=0;i<TESTS;i++) {
    sprintf(namein,"syrup.%02i.in",i+1);

    fin.open(namein);
    for (int j=0;j<4;j++) fin<<A[i][j]<<' ';
    fin<<A[i][4]<<endl;
    fin.close();

    sprintf(exename,"syrup.exe <syrup.%02i.in >syrup.%02i.sol",i+1,i+1);
    system(exename);

  }

  return 0;
}
