#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct Mish{
  char s;
  int k;
};
int bMis, bSir,ba;
Mish a[2000001];

int sR ( Mish p, Mish q) {
  if (p.k>q.k)
   return 0;
   else
   if (p.k<q.k)
    return 1;
    else{
     if (p.s<q.s)
     return 1;
     else
     return 0;
    }
}
int sL ( Mish p, Mish q) {
  if (p.k>q.k)
   return 0;
   else
   if (p.k<q.k)
    return 1;
    else{
     if (p.s<q.s)
     return 0;
     else
     return 1;
    }
}


int main()
{
    int i,k;
    int bS=0, bMR=0, bML=0, bIntL, bIntR, bML1=0, bMR1=0;

    cin>>bMis;
    a[0].s='d';
    a[0].k=-1;
    for (i=1; i<=bMis; i++) {
      scanf ("%d",&a[i].k);
      a[i].s='m';
    }
    cin>>bSir;
    for (i=1; i<=bSir; i++) {
      scanf ("%d",&a[i+bMis].k);
      a[i+bMis].s='s';
    }
    ba=bMis+bSir;

    sort(a+1,a+ba+1,sR);
    bMR=0; bIntR=0;
    if (a[1].s=='m') {
      bMR=1;
      bIntR=1;
    }
    for (i=2;i<=ba;i++)
      if (a[i].s=='m') {
        bMR++;
        if (a[i-1].s=='s') bIntR++;
       }
       else {
        if (bMR>0)
         bMR--;
      }
    sort(a+1,a+ba+1,sL);
    bML=0; bIntL=0;
    if (a[ba].s=='m') {
      bML=1;
      bIntL=1;
    }
    for (i=ba-1;i>=1;i--)
      if (a[i].s=='m') {
        bML++;
        if (a[i+1].s=='s') bIntL++;
       }
       else {
        if (bML>0)
         bML--;
      }

    bMR1=bMis-(bIntR-1);
    if (a[ba].s=='s') bMR1--;

    bML1=bMis-(bIntL-1);
    if (a[1].s=='s') bML1--;
    if (bML<bMR) cout<<"L "<<bML;
    else
    if (bMR<bML) cout<<"R "<<bMR;
    else
    cout<<"D "<<bMR;
    cout<<endl;
    if (bML1<bMR1) cout<<"L "<<bML1;
    else
    if (bMR1<bML1) cout<<"R "<<bMR1;
    else
    cout<<"D "<<bMR1;
    cout<<endl;

   // system ("pause");
	return 0;
}
/*

4
1 2 3 5
5
2 2 3 3 4

*/
