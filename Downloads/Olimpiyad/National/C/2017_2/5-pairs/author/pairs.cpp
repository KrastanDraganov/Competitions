#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int INT;
const int N=2002;

INT a[N];
INT d[N*N];
int s[N*N];
int n;

int main()
 {
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    int nd=0;

    for(int i=0; i<n; i++)
     for(int j=i+1; j<n; j++)
       {d[nd] = a[i]*a[j]; nd++;}

    sort(d, d+nd);

    int r=0;
    int c=1;
    for(int i=1;i<nd;i++)
      if(d[i-1]==d[i]) c++;
      else{if(c>r){r=c;} c=1;}

    if(c>r)r=c;

    cout << r << endl;

    int ns=0;

    c=1;

    for(int i=1;i<nd;i++)
    {
      if(d[i-1]==d[i]) c++;
      else {if(c==r){s[ns++]=i-1;} c=1;}
    }


    if(c>1) if(c==r) s[ns++] = nd-1;

    if(r==1)
    if(d[nd-2]!=d[nd-1]) s[ns++]=nd-1;

    cout << ns << endl;

    for(int k=0;k<ns;k++)
    { cout << d[s[k]] << " ";
      bool b=false;
      for(int i=0; i<n; i++)
      { if(b) break;
        for(int j=i+1; j<n; j++)
        if(a[i]*a[j]==d[s[k]])
        { cout << i+1 << " " << j+1 << endl;
          if(k==99) return 0;
          b=true;
          break;
        }
      }
    }
}
