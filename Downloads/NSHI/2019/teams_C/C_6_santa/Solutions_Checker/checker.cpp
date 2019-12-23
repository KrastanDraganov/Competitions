/* the checker has three arguments:
   - first - name of the input file
   - second - name of the correct_output file
   - third - name of the contestant_output file
    */
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<stack>
using namespace std;
stack <int> one,two;
char queries[200001],output[100001];
int main (int argc, char** argv) {
    FILE *in1,*out1,*ans1,*out=stdout,*err=stderr;
    int n,m,i,cnt1=1,cnt2=1;
    if (argc<3) {
       fprintf(out,"-3\n");
       fprintf(err,"The checker needs arguments!\n");
       return -3;
       }
    in1=fopen(argv[1],"rt");
    if (!in1) {
       fprintf(out,"-1\n");
       fprintf(err,"Could not open input file!\n");
       return -1;
       }
    ans1=fopen(argv[2],"rt");
    if (!out1) {
       fprintf(out,"-1\n");
       fprintf(err,"Could not open answer file!\n");
       return -1;
       }
    out1=fopen(argv[3],"rt");
    if (!ans1) {
       fprintf(out,"-1\n");
       fprintf(err,"Could not open output file!\n");
       return -1;
       }
    fscanf(in1,"%d",&n);
    fscanf(in1,"%s",&queries);
    for (i=0; i<2*n; i++) {
        for (;;) {
            if (!fgets(output,100000,out1)) {
               fprintf(out,"0\n");
               fprintf(err,"No output!\n");
               return 0;
               }
             m=strlen(output);
             output[m-1]='\0';
             m--;
             if ((m!=1)&&(m!=3)) {
                fprintf(out,"0\n");
                fprintf(err,"Wrong type of output!\n");
                return 0;
                }
            if (m==1) {
               if (queries[i]=='1') {
                  if (output[0]=='1') one.push(cnt1++);
                  else if (output[0]=='2') two.push(cnt1++);
                  else {
                    fprintf(out,"0\n");
                    fprintf(err,"Wrong number!\n");
                    return 0;
                    }
                  }
               else {
                   if (output[0]=='1') {
                      if (one.empty()==1) {
                         fprintf(out,"0\n");
                         fprintf(err,"%dEmpty tape!\n",i);
                         return 0;
                         }
                      else if (one.top()!=cnt2) {
                              fprintf(out,"0\n");
                              fprintf(err,"Elf not found!\n");
                              return 0;
                              }
                      one.pop();
                      }
                   else {
                      if (two.empty()==1) {
                         fprintf(out,"0\n");
                         fprintf(err,"Empty tape!\n");
                         return 0;
                         }
                      else if (two.top()!=cnt2) {
                              fprintf(out,"0\n");
                              fprintf(err,"Elf is not on top!\n");
                              return 0;
                              }
                      two.pop();
                      }
                   cnt2++;
                   }
               break;
               }
            else if (strcmp(output,"1 2")==0) {
                    if (one.empty()==1) {
                       fprintf(out,"0\n");
                       fprintf(err,"Empty tape!\n");
                       return 0;
                       }
                    two.push(one.top());
                    one.pop();
                    }
            else if (strcmp(output,"2 1")==0) {
                    if (two.empty()==1) {
                       fprintf(out,"0\n");
                       fprintf(err,"Empty tape!\n");
                       return 0;
                       }
                    one.push(two.top());
                    two.pop();
                    }
            else {
                fprintf(out,"0\n");
                fprintf(err,"Wrong type of output!\n");
                return 0;
                }
            }
        }
    fprintf(out,"1\n");
    fprintf(err,"OK!\n");
    return 0;
}
