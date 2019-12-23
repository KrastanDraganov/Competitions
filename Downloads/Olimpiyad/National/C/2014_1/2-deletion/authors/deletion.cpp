//Task: deletion
//Author: Kinka Kirilova-Lupanova
#include <iostream>
#include <math.h>
using namespace std;
        
int main()
{ int   n, i, ka, j, a[5];
  long long f2=0, f20=0, f201=0, f2014=0;
  cin>>n; 
  ka=0;
  a[0]=1;
  for (i=1;i<n; i++)
      {j=0; 
       while (j<=ka && a[j]==9)
             {a[j]=0; 
              j++;
             }   
       if (j<=ka)  a[j]++; 
       else 
            {ka++; 
             a[ka]=1;
            }
       for (j=ka;j>=0;j--)
       switch (a[j])
               {case 2 : f2++; break;
                case 0 : f20=f20+f2;  break;
                case 1 : f201=f201+f20;break;
                case 4 : f2014=f2014+f201;break;
               };
     }
  cout<<f2014<<endl;      
  return 0;
}  

 



 
