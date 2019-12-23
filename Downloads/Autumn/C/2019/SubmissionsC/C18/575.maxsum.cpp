#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],k,b[1001],din1[100001],din2[100001],maxi;
bool iv=0;
int main()  {
cin>>n>>k;
for (int q=0;q<n;q++) cin>>a[q];
for (int q=0;q<k;q++) cin>>b[q];
din1[0]=a[0];
for (int q=1;q<n;q++) {
     maxi=-100000000;
     iv=0;
    for (int w=0;w<k;w++) {
        if (b[w]>q) {}
        else {
                iv=1;
            maxi=max(maxi,din1[q-b[w]]);
        }
      if (iv)  din1[q]=maxi+a[q];
      else din1[q]=-100000000;
    }
}
din2[n-1]=a[n-1];
for (int q=n-2;q>=0;q--) {
     maxi=-100000000;
     iv=0;
    for (int w=0;w<k;w++) {
        if (b[w]>n-q-1) {}
        else {
                iv=1;
            maxi=max(maxi,din2[q+b[w]]);
            }
      if (iv)  din2[q]=maxi+a[q];
      else din2[q]=-100000000;
    }
}
long long le2=din1[0],nm=din1[0]+din2[1];
for (int q=2;q<n;q++) {
    le2=max(le2,din1[q-1]);
    if (din2[q]+le2>nm) {
        nm=din2[q]+le2;
    }
}
cout<<nm<<"\n";
}
