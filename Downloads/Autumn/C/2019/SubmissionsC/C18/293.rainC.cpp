#include<bits/stdc++.h>
using namespace std;
long long a[1000000],n,k,maxa[1000000],ngd1[1000000];
bool b[1000000];
pair<long long,long long> cokyl[1000000];
int main() {
cin>>n;
for (int q=0;q<n;q++) {cin>>a[q];maxa[q]=a[q];}
cin>>k;
long long llll,lll;
for (int q=0;q<k;q++) {cin>>llll>>lll;maxa[llll]=maxa[llll]+lll;}
long long maxvis=maxa[0],mind=0;
cokyl[0].first=0;
for (int q=1;q<n;q++) {
    if (maxa[q]<maxvis) {cokyl[q].first=mind;}
    else {
        if (maxa[q]==maxvis) {
            if (a[q]==maxa[q]) {
             cokyl[q].first=mind;
        maxvis=maxa[q];
        mind=q;
            }
            else {
              cokyl[q].first=mind;
            }
        }
        else {
        cokyl[q].first=mind;
        maxvis=maxa[q];
        mind=q;
        }
    }
}
maxvis=maxa[n-1],mind=n-1;
cokyl[n-1].second=n-1;
for (int q=n-2;q>=0;q--) {
  if (maxa[q]<maxvis) {cokyl[q].second=mind;}
    else {
        if (maxa[q]==maxvis) {
            if (a[q]==maxa[q]) {
             cokyl[q].second=mind;
        maxvis=maxa[q];
        mind=q;
            }
            else {
              cokyl[q].second=mind;
            }
        }
        else {
        cokyl[q].second=mind;
        maxvis=maxa[q];
        mind=q;
        }
    }
}

for (int q=0;q<n;q++) {
    if (maxa[q]>a[q]) {
        if (a[cokyl[q].first]==maxa[cokyl[q].first] and a[cokyl[q].second]==maxa[cokyl[q].second]) {
        if (maxa[cokyl[q].first]<maxa[q]) {
            ///cout<<"q alone cokyl2 "<<q<<" "<<cokyl[q].second<<"\n";
            b[q]=1;
        }
        else {
            if (maxa[cokyl[q].second]<maxa[q]) {
             //   cout<<"q alone cokyl1 "<<q<<" "<<cokyl[q].first<<"\n";
            b[q]=1;
            }
        }
        }
        else {
            if (a[cokyl[q].first]!=maxa[cokyl[q].first] and a[cokyl[q].second]!=maxa[cokyl[q].second]) {
                if (maxa[cokyl[q].first]==maxa[cokyl[q].second]) {}
                else {
                    if (maxa[q]<maxa[cokyl[q].first] and maxa[q]<maxa[cokyl[q].second]) {}
                    else {
                        if (maxa[q]>maxa[cokyl[q].first]) {
                           //cout<<"q>cokyl2 "<<q<<" "<<cokyl[q].second<<"\n";
                            b[q]=1;
                            b[cokyl[q].second]=1;
                        }
                        else {
                          //  cout<<"q>cokyl1 "<<q<<" "<<cokyl[q].first<<"\n";
                            b[q]=1;
                            b[cokyl[q].first]=1;
                        }
                    }
                }
            }
            else {
                if (maxa[cokyl[q].first]==maxa[cokyl[q].second]) {\
                    if (cokyl[q].first==q) {
                        b[q]=1;
                        if (maxa[cokyl[q].second]!=a[cokyl[q].second]) b[cokyl[q].second]=1;
                    }
                    else {
                        if (cokyl[q].second==q) {
                            b[q]=1;
                            if (maxa[cokyl[q].first]!=a[cokyl[q].first]) {b[cokyl[q].first]=1;}
                        }
                    }
                }
                else {
                if (a[cokyl[q].first]!=maxa[cokyl[q].first]) {
                   // cout<<"q and cokyl1 "<<q<<" "<<cokyl[q].first<<"\n";
                    b[q]=1;
                    b[cokyl[q].first]=1;
                }
                else {
                   // cout<<"q and cokyl2 "<<q<<" "<<cokyl[q].second<<"\n";
                    b[q]=1;
                    b[cokyl[q].second]=1;
                }
                }
            }
        }
    }
}

long long br=0;
for (int q=0;q<n;q++) {
//  cout<<b[q]<<" ";
  if (b[q]) {
    br++;
    a[q]=maxa[q];
  }
}
cout<<br;
long long ngd=a[n-1],ngdi=n-1,ksm=0;
ngd1[n-1]=-1;
for (int q=n-2;q>=0;q--) {
    if (a[q]<ngd) ngd1[q]=ngdi;
    else {
        ngd1[q]=ngdi;
        ngd=a[q];
        ngdi=q;

    }
}
/*
for (int q=0;q<n;q++) cout<<a[q]<<" ";
cout<<endl;
for (int q=0;q<n;q++) cout<<ngd1[q]<<" ";
*/
for (int q=0;q<n-1;q=q) {
        ksm+=(ngd1[q]-q)*min(a[q],a[ngd1[q]]);
        q=ngd1[q];
}
cout<<" "<<ksm<<"\n";
}
/*
6
2 4 2 4 2 1
2
2 1
4 1

10
0 1 3 1 1 2 3 4 1 2
7
0 1
1 1
3  3
4 1
5 1
6 1
9 2
*/
