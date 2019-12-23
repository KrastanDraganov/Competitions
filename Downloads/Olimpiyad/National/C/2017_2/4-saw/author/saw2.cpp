//Task: saw
//Author: Kinka Kirilova-Lupanova

#include <iostream>
using namespace std;
long long ans;
 
 void backtrack( int prev, int n, int dir)
{ int d;
  if (dir == 1) 
     {for (d = prev + 1; d<=9; d++)
          if (n > 1) backtrack(d, n - 1, 2);
          else ans++;
     }
  else 
     {for (d= 0; d<=prev - 1;d++) 
          if (n > 1) backtrack(d, n - 1, 1);
          else ans++;
     }
}

int main()
{ int n,i;
  cin>>n;
  
  for (i= 1; i<=9;i++)
     {backtrack(i, n - 1, 1);
      backtrack(i, n - 1, 2);
     }
 cout<<ans<<endl;
return 0;
}

//45 to4ki  
  
