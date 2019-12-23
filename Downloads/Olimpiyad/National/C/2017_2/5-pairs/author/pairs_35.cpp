#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

typedef long long int INT;

INT a[2002];
INT d[5002*5002];
int n;

typedef unordered_map<INT, pair<int,int> >H;
typedef unordered_multiset<INT> S;


int main()
{
 cin >> n;
 for(int i=0;i<n;i++) cin >> a[i];

 INT maxp=0;
 INT minp=LLONG_MAX;
 int maxr=0;
 H h;
 S s;
 int k=0;
 int kd=0;
 for (int i=n-1; i>=0; i--)
 for (int j=n-1; j>=i+1; j--)
 {
  INT p=a[i]*a[j];
  if(maxp<p) maxp=p;
  if(minp>p) minp=p;
  h[p]=make_pair(i,j);
  if(s.count(p)==0) {d[kd]=p; kd++;}
  s.insert(p);
  if(maxr<s.count(p)) maxr=s.count(p);
  k++;
 }


cout << maxr << endl;

 INT r1=minp;
 INT r2=maxp;
 int nr=maxr;

 sort(d,d+kd);

 int cc=0;
 for (int t=0;t<kd;t++)
 {
  INT r=d[t];
  if(s.count(r)>=nr) cc++;
 }

 cout << cc << endl;

 for (int t=0;t<kd;t++)
 {
  INT r=d[t];
  if(s.count(r)>=nr)
  {
   int i1=h[r].first;
   int j1=h[r].second;
   cout << r << " " << i1+1 << " " << j1+1;
   cout << endl;
  }
 }

}

