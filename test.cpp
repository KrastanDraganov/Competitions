//Not mine code

//Task: investor
//Author: Kinka Kirilova-Lupanova

  #include <iostream>
  #include <math.h>
  using namespace std;
  
  long long f[60], s;
int n;

 long long gcd(long long a, long long b)
 {long long r;
  while (b!=0)    
    {r=a%b;
     a=b;
     b=r;
    }
  return a;
  } 
void extended_euclid(long long a, long long b, long long &x1, long long &y1)
{ int q, r, x2,  y2,  t;
  x1 = 1; y1 = 0;
  x2 = 0; y2 = 1; 
  while (b != 0) 
        {q = a/ b; 
         r = a % b;
         a=b;b=r;
         t=x2;
         x2=x1-q*x2;
         x1=t;
         t=y2;
         y2=y1-q*y2;
         y1=t;
        } 
}

  int main()
{long long d,c,x0,y0,kmin, kmax, res;
  	int i, k=1;
    cin>>n>>c;
	f[1] = 1;
	f[2] = 1;
	for (i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i  - 2];
	}
long long a, b, x, y, t;
	a = f[n - 2];
	b = f[n - 1];
 d=gcd(a,b);
 if (c%d==0) 
  {a=a/d;b=b/d;c=c/d;
   extended_euclid(a,b, x, y);
   x0=x*c; y0=y*c;
      
   if (x0 % b == 0) kmin=-1 * x0 / b +1;
   else  kmin = (long long)ceil(-1.0 * x0 / b); 
   
   if (y0% a==0) kmax=y0 / a-1;
   else kmax = (long long)floor(1.0 * y0 / a);
    cout<<kmin<<" "<<kmax<<" "<<d<<" "<<x0<<" "<<y0<<" "<<a<<" "<<b<<endl;
   if (kmin>kmax) cout<<"0"<<endl;
   else 
        {res = kmax - kmin + 1;
         cout<<res<<endl;
        } 
  }
 else cout<<"0\n";  
 return 0;
}  

    
