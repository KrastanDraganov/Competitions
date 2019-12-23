#include<iostream>
#include<iomanip>
using namespace std;

int a[100001], d1[100001], d2[100001];
int n;

int p[100001];

int r;

void show(int k)
{
 int sum=a[0];   
 int c=0;
 for(int i=0;i<k-1;i++) 
 {
   c=c+p[i];
   sum = sum + a[c];        
 }
// cout << setw(5) << sum << " : ";
 if(r<sum) r=sum;
// for(int i=0;i<k-1;i++) cout << setw(3) << p[i];
// cout << endl;    
}

void gen(int i, int s)
{
 if(s<=n) show(i);
 if(s==n) {/*show(i)*/; return; }
 if(s>n) return;    
 p[i]=1; gen(i+1, s+1);
 if(p[i-1]==1) {p[i]=2; gen(i+1,s+2);}  
}



int main()
{
 cin >> n;
 for(int i=0;i<n;i++) cin >> a[i];
  
  r=-999999999;
  p[0]=1;
  gen(1,1);
  p[0]=2;
  gen(1,2);
  
  
//  cout << "r=" << r << endl;
  cout << r << endl;
    
}
