#include <bits/stdc++.h>
using namespace std;
  int A[1000002], B[1000002], C[1000002], D[1000002], E[1000002];
  pair<int,int> a[1000001];
  int mod (int a){
    if (a<0){
      a=1000001;
    }
    return a;
  }
int main (){
ios_base::sync_with_stdio(false);
cin.tie(0);
  A[1000001]=10000000;
  long long n, i, k, j, x=0, y=0, lic=0, m=0;
   cin >> n;
  for (i=1; i<=n; i++){
    cin >> A[i];
  }
  cin >> k;
  for (i=0; i<k; i++){
    cin >> a[i].first >> a[i].second;
    A[++a[i].first]+=a[i].second;
  }
  for(i=1; i<=n; i++){
    if (A[i]>=A[x]) {
      B[x]=i;
      D[i]=x;
      x=i;
    }
    else {
      B[i]=-1;
      D[i]=-1;
    }
  }
  x=n+1;
  for(i=n; i>0; i--){
    if (A[i]>=A[x]) {
      C[x]=i;
      E[i]=x;
      x=i;
    }
    else {
      C[i]=-1;
      E[i]=-1;
    }
  }
  m=k;
  for (i=0; i<k; i++){
    int z=a[i].first;
    if ((B[z]==-1 and C[z]==-1 and D[z]==-1 and E[z]==-1)or (A[mod(D[z])]>A[z]-a[i].second and A[mod(E[z])]>A[z]-a[i].second)) {
      m--;
    }
    else {
      if (A[mod(D[z])]<=A[z]-a[i].second and A[mod(E[z])]<=A[z]-a[i].second) {
        m--;
      }
    }
  }
  i=1;
  while (true){
    if (B[i]==0){
      break;
    }
    lic+=(B[i]-i)*A[i];
    i=B[i];
  }
  int p=i;
  i=n;
  while (i>p){
    if (C[i]==0){
      break;
    }
    lic+=(i-C[i])*A[i];
    i=C[i];
  }
  cout << m << " " << lic << endl;
 return 0;
}
