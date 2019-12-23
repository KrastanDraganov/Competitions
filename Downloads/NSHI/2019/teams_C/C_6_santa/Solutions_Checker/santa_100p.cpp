#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stack>
using namespace std;
stack <int> one,two;
char queries[200001];
int main () {
    int n,i,cnt1=1,cnt2=1;
    scanf("%d",&n);
    scanf("%s",&queries);
    for (i=0; i<2*n; i++) {
        if (queries[i]=='1') {
           printf("1\n");
           one.push(cnt1++);
           }
        else {
            if ((two.empty()==1)||(two.top()!=cnt2)) {
               for (;;) {
                   if (one.empty()==1) break;
                   two.push(one.top());
                   printf("1 2\n");
                   one.pop();
                   }
               }
            printf("2\n");
            two.pop();
            cnt2++;
            }
        }
    return 0;
}
