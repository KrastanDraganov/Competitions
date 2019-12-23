//Task: saw
//Author: Kinka Kirilova-Lupanova

#include <iostream>
using namespace std;
long long  g[23][11], l[23][11], ans;
int main()
{
 int  n, i, j, k;
 cin>>n;
 for (i =1;i<=9; i++) 
    {g[1][i] = 1; 
     l[1][i] = 1;
    }
  for (i=1; i<=n-1;i++) 
    for (j= 0; j<=9;j++) 
      {for (k=j + 1; k<= 9; k++) 
        l[i + 1][k]= l[i + 1][k] + g[i][j];//+
       for (k = 0; k<= j - 1;k++) 
        g[i + 1][k] = g[i + 1][k] + l[i][j];//+
      }  
  for (j = 0;j<=9;j++)
    ans = ans + l[n][j] + g[n][j];
  cout<<ans<<endl;
return 0;
}
//100
