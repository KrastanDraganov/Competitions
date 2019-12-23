#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
char text[10000001],word[101];
int main () {
    int n,m,k,i,j,h,br,last,len,fl;
    scanf("%s%s%d",&text,&word,&k);
    n=strlen(text); m=strlen(word);
    for (i=n-1; i>=0; i--) {
        br=0; last=-n;
        for (j=0; j<n-m+1; j++) {
            fl=0;
            for (h=j; h<j+m; h++) {
                if (text[h]!=word[h-j]) {
                   fl++;
                   break;
                   }
                }
            if (fl==0) {
               if (j-last>=i+m) {
                  br++; last=j;
                  }
               }
            }
        if (br>=k) break;
        }
    cout << i ;
    cout << endl ;
    return 0;
}
