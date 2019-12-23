//Task: guess
//Author: Kinka Kirilova-Lupanova
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int  i, n, x, y, g=0, maxy=0, cnt=0, sq, ans[5001];

int  GCD(int a,int b)
{ int r;
  while (b!=0) 
  {r=a%b;
   a=b;b=r;
  }
  return a;
}

int main()
{
 cin>>n;
 for (i= 0;i<=n - 1;i++)
     {cin>>x>>y;
      if (i == 0) g= x - y;
      else g= GCD(g, x - y);
      if (y > maxy)  maxy= y;
     }
 sq= (int)(floor(sqrt(g)));
 for (i= 1;i<=sq; i++) 
     {if (g % i == 0) 
         {if (i > maxy) 
            {ans[cnt] = i;
             cnt++;
            }
          if (g / i > maxy && g / i != i) 
             {ans[cnt]= g / i;
              cnt++;
             }
          }
      }
   cout<<cnt<<endl;
   if (cnt!=0)
      {sort(ans, ans+cnt);
       for (i = 0;i<cnt - 1;i++) cout<<ans[i]<<" "; 
       cout<< ans[cnt-1]; 
       cout<<endl;
      } 
        return 0;
}
