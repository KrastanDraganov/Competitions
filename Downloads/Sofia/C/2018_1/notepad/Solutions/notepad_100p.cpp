#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
char text[10000001],word[101];
vector <int> ind;
int main () {
    int n,m,k,i,l,r,mid,br,last,len;
    unsigned long long int code=0,curcode=0,st;
    scanf("%s%s%d",&text,&word,&k);
    n=strlen(text); m=strlen(word);
    st=1;
    for (i=0; i<m; i++) {
        code*=2;
        code+=(word[i]-'a');
        st*=2;
        }
    st/=2;
    curcode=0;
    for (i=0; i<m; i++) {
        curcode*=2;
        curcode+=(text[i]-'a');
        }
    if (curcode==code) ind.push_back(m-1);
    for (i=m; i<n; i++) {
        curcode-=st*(text[i-m]-'a');
        curcode*=2;
        curcode+=(text[i]-'a');
        if (curcode==code) ind.push_back(i);
        }
    len=ind.size();
    l=-1; r=n;
    for (;;) {
        if (l==r-1) break;
        mid=(l+r)/2;
        br=0; last=-n;
        for (i=0; i<len; i++) {
            if (ind[i]-last>=mid+m) {
               br++; last=ind[i];
               }
            }
        if (br>=k) l=mid;
        else r=mid;
        }
    cout << l ;
    cout << endl ;
    return 0;
}
