#include<iostream>
using namespace std;

long long int mod=1000000007;
long long int d[102][1<<12];
int m,n;

long long int md(long long int a)
{
  long long int r=a%mod;
  while(r<0) r +=mod;
  return r;
}

bool ok(int mask, int new_mask)
{
  for(int i=0;i<m;i++)
  {
    int a = (bool)(mask&(1<<i));
    int b = (bool)(new_mask&(1<<i));
    if((a==1)&&(b==1)) return false;
    if(a==0)
    {
      if(b==1) continue;
      if(b==0)
      {
        if(i==m-1) return false;
        if(i+1<m)
        {
          if((bool)(mask&(1<<(i+1)))==0)
            mask=mask|(1<<(i+1));
          else return false;
        }
      }
    }
  }

  return true;
}

void solve()
{

  if(n<m) swap(n,m);
  d[0][0]=1;
  for(int i=0;i<n;i++)
  for(int mask=0;mask<(1<<m);mask++)
  {
    for(int new_mask=0;new_mask<(1<<m);new_mask++)
     if(ok(mask,new_mask))
      d[i+1][new_mask] = (d[i+1][new_mask]+d[i][mask])%mod;
  }

  cout << d[n][0] << endl;
}

void solve2()
{
  long long int a,b,r;
  a=1;
  b=2;

  if(n==1) {cout << a; return;}
  if(n==2) {cout << b; return;}

  for(int k=3;k<=n;k++)
  {
    r=(a+b)%mod;
    a=b;
    b=r;
  }

  cout << r << endl;
}

void solve3()
{


  n=n/2;

  long long int a,b,r;
  a=3;
  b=11;

  if(n==1) {cout << a; return;}
  if(n==2) {cout << b; return;}

  for(int k=3;k<=n;k++)
  {

    r=md(4*b-a);
    a=b;
    b=r;
  }

  cout << r << endl;
}


void solve4()
{
  long long int a,b,c,d,r;
  a=1;
  b=5;
  c=11;
  d=36;

  if(n==1) {cout << a; return;}
  if(n==2) {cout << b; return;}
  if(n==3) {cout << c; return;}
  if(n==4) {cout << d; return;}

  for(int k=5;k<=n;k++)
  {
    r=md(d+5*c+b-a);
    a=b;
    b=c;
    c=d;
    d=r;
  }

  cout << r << endl;
}

int main()
{
 cin >> n >> m;
 if((n*m)%2==1) {cout << 0 << endl; return 0;}
 if(n<m) swap(n,m);

  if(m==2) solve2();
  else if(m==3) solve3();
  else if(m==4) solve4();
  else
    solve();

}
