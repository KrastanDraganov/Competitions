//Task: saw
//Author: Kinka Kirilova-Lupanova

#include <iostream>
using namespace std;
 long long ans, n, p, i, j, first, last, a[10];
 bool ok;
int main()
{cin>>n;
 p= 1;
 for (i = 1;i<=n - 1;i++) 
    p = p * 10;
 first = p;
 last = p * 10 - 1;
 for (i = first; i<=last; i++) 
    {p= i;
     for (j= 1; j<= n; j++) 
         {a[j]= p % 10;
          p = p / 10;
         }
     ok = true;
     for (j = 2; j<= n - 1; j++) 
        if (!((a[j] < a[j - 1]) &&(a[j] < a[j + 1]) || (a[j] > a[j - 1]) && (a[j] > a[j + 1]))) 
           ok = false;
     if (ok) ans++;
    }
 cout<<ans<<endl;
return 0;
}

//25 to4ki  
  
