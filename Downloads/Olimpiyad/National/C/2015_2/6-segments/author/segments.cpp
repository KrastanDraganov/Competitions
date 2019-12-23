#include<iostream>
#include<algorithm>
using namespace std;

const int N=600001;
struct pp {long long int x; int c;} p[N];

long long int up(long long int a, long long int b)
{
  long long int q=a/b;
  long long int r=a%b;
  if(r==0) return q;
  else if(r<0) return q;
  else return q+1;
}

long long int up0(long long int a, long long int b)
{
  long long int q=a/b;
  long long int r=a%b;
  if(r==0) return q+1;
  if(r<0) return q;
  else return q+1;
}

long long int down(long long int a, long long int b)
{
  long long int q=a/b;
  long long int r=a%b;
  if(r==0) return q;
  else if(r>0) return q;
  else return q-1;
}

long long int down0(long long int a, long long int b)
{
  long long int q=a/b;
  long long int r=a%b;
  if(r==0) return q-1;
  if(r>0) return q;
  else return q-1;
}

long long int convert(char c, long long int a, long long int b)
{
 if(c=='[') return up(a,b);
 if(c=='(') return up0(a,b);
 if(c==']') return down(a,b);
 if(c==')') return down0(a,b);
}

bool cmp(pp a, pp b)
{
  if(a.x<b.x) return true;
  if(a.x>b.x) return false;
  if(a.c>b.c) return true;
  return false;
}

int main()
{
/*
 long long int aa=-19;
 long long int bb=20;
 cout << (double)aa/(double)bb << endl;
 cout << convert('[',aa,bb);
 return 0;
*/

 int n;
 cin >> n;
 char c1; long long int a1,b1; long long int a2, b2; char c2;
 long long int ax, bx;
 int k=0;
 for(int i=1;i<=n;i++)
 {
   cin >> c1 >> a1 >> b1 >> a2 >> b2 >> c2;

   ax=convert(c1,a1,b1);
   bx=convert(c2,a2,b2);
   if(bx<ax) continue;

   p[k].x=ax; p[k].c=1;
   k++;
   p[k].x=bx; p[k].c=-1;
   k++;
 }

 sort(p, p+k, cmp);

 long long int cnt=0;
 int t=1;
 long long int a=p[0].x;
 long long int b=a;
 bool f=false;
 for(int j=1;j<k; j++)
 {
   if(t==0) {f=true; cnt += (b-a+1);}
   t += p[j].c;
   b=p[j].x;
   if(f) {a=p[j].x;f=false;}
 }
 cnt += (b-a+1);

 cout << cnt << endl;

}
