#include <bits/stdc++.h>
using namespace std;
      long long A[27], B[27];

  string a;
int main (){
ios_base::sync_with_stdio(false);
cin.tie(0);
  long long n, m, k, i, j, p, br;
  cin >> n >> m >> k;
    if (k==1){
      for (i=0; i<n; i++) {
        cin >> a;
        p=a.length();
        for (j=0; j<p; j++){
          B[a[j]-'a']=1;
        }
        for (j=0; j<27; j++){
          A[j]+=B[j];
        }
        for (j=0; j<27; j++){
          B[j]=0;
        }

      }
      p=0;
      br=1;
      for (i=1; i<27; i++) {
        if (A[i]>A[p]){
          p=i;
          br=0;
        }
        if (A[i]==A[p]){
          br+=1;
        }
      }
      cout << A[p] << endl;
      cout << char(p+'a') << endl;
      cout << br << endl;
      return 0;
    }
  cout << 0 << endl;



 return 0;
}
/*
4 10 1
abcde
bcdef
cdefg
defgh
*/
