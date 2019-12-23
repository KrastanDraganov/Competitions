#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stack>
using namespace std;
stack <int> one,two;
char queries[200001];
int tape[100001];
int main () {
    int n,i,cnt1=1,cnt2=1;
    scanf("%d",&n);
    scanf("%s",&queries);
    for (i=0; i<2*n; i++) {
        if (queries[i]=='1') {
           if (one.empty()==1) {
              printf("1\n");
              tape[cnt1]=1;
              one.push(cnt1++);
              }
           else if (two.empty()==1) {
                   printf("2\n");
                   tape[cnt1]=2;
                   two.push(cnt1++);
                   }
           else if (one.top()<two.top()) {
                   printf("1\n");
                   tape[cnt1]=1;
                   one.push(cnt1++);
                   }
           else {
               printf("2\n");
               tape[cnt1]=2;
               two.push(cnt1++);
               }
           }
        else {
            if (tape[cnt2]==1) {
               for (;;) {
                   if ((one.empty()==1)||(one.top()==cnt2)) break;
                   two.push(one.top());
                   tape[one.top()]=2;
                   printf("1 2\n");
                   one.pop();
                   }
               printf("1\n");
               one.pop();
               }
            else {
                for (;;) {
                   if ((two.empty()==1)||(two.top()==cnt2)) break;
                   one.push(two.top());
                   tape[two.top()]=1;
                   printf("2 1\n");
                   two.pop();
                   }
               printf("2\n");
               two.pop();
               }
            cnt2++;
            }
        }
    return 0;
}
