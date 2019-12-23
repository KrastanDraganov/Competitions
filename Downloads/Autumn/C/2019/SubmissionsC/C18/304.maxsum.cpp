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
     maxi=0;
     iv=0;
    for (int w=0;w<k;w++) {
        if (b[w]>q) {}
        else {
                if (b[w]!=0) {
                iv=1;
            maxi=max(maxi,din1[q-b[w]]);
        }
        }
      if (iv)  din1[q]=maxi+a[q];
      else din1[q]=-100000000;
    }
}
din2[n-1]=a[n-1];
for (int q=n-2;q>=0;q--) {
     maxi=0;
     iv=0;
    for (int w=0;w<k;w++) {
        if (b[w]>n-q-1) {}
        else {if (b[w]!=0) {
                iv=1;
            maxi=max(maxi,din2[q+b[w]]);}
        }
      if (iv)  din2[q]=maxi+a[q];
      else din2[q]=-100000000;
    }
}
long long le2=a[n-1],nm=din1[n-2]+din2[n-1];
for (int q=n-3;q>=0;q--) {
    le2=max(le2,din2[q+1]);
    if (din1[q]+le2>nm) {
        nm=din1[q]+le2;
    }
}
cout<<nm<<"\n";
}
