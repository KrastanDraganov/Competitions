//Task: zeros
//Author: Kinka Kirilova-Lupanova
#include <iostream>
int a[3000001];

using namespace std;

 struct number 
      {int len;
       short digits[10000];
      };
  
   void set1(number &n)
  {
      n.len = 1;
      n.digits[1] = 1;
}

   void mulsh(number &n, int m)
   { int carry;
   int i; i;
      carry = 0;
      for (i = 1;i<= n.len;i++) 
         { carry = carry + n.digits[i] * m;
           n.digits[i] = carry % 10;
           carry = carry / 10;
         }
      while (carry > 0) 
         {n.len++;
          n.digits[n.len] = carry % 10;
          carry = carry / 10;
         }
  }

   void divsh(number &n, int m )
   { int rem;
   int i ;
      rem = 0;
      for (i = n.len;i>= 1;i--) 
         {rem = rem * 10 + n.digits[i];
          n.digits[i]= rem / m;
          rem = rem % m;
         }
      if (rem != 0) return ;
      while (n.digits[n.len] == 0) 
         n.len--;
  }

   int count0(number &n ) 
   { int cnt, t, p, i ;
      cnt = 0;
      t = n.digits[n.len];
      for (i= n.len; i>= 1;i--) 
         if (n.digits[i] == 0)  cnt = cnt + 1;
      return  cnt;
}

int main()
{int n, k, i ;
  number ans ;
   cin>>n>>k;
   if (2 * k > n)  k = n - k;
   set1(ans);
   for (i = 1;i<=k; i++) 
      {mulsh(ans, n + 1 - i);
      divsh(ans, i);
  }
   cout<<count0(ans)<<endl;
return 0;
}                       


