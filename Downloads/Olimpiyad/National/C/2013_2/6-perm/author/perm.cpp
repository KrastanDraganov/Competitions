#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

int N;
char c[500001];
int i,j,d;
int p1,mx, dd, nom[500001];

int main() {
    cin>>N;
    for (i=1;i<N;i++) cin>>c[i];
    mx=0; p1=0;
    for (i=1;i<N;i++) 
     if (c[i]=='<') {
      if (p1==0)       
       nom[i]=++mx;
       else {
        mx++;
        nom[i]=mx;
        for (j=i-1;j>=p1;j--) nom[j]=++mx;
        p1=0;
       }
     }
     else 
     if (p1==0)
      p1=i;
    if (c[N-1]=='<') 
     nom[N]=N;
     else {
       nom[N]=++mx;
       if (p1>0)
        for (j=N-1;j>=p1;j--) nom[j]=++mx;
     }
    for (i=1; i<=N; i++)
     printf("%d ", nom[i]);
    cout << endl;

	return 0;
}
/*
9
><<><><<

7
<>>><<
5
<<<<
5
>>>>
5
<><>
6
><><>
9
>>><<<><>
8
<<><>><
6
<>>><
7
>><><<
    c[1]='>';
    c[2]='>';
    c[3]='<';
    c[4]='<';
    c[5]='>';
    c[6]='<';
    c[7]='<';
    c[8]='<';
*/
