/* the checker has three arguments:
   - first - state of checking with three possible values:
              = 0 - checks the solution file according the answer file
              = 1 - generates solution file with name from the third argument using the first solution
              = 2 - generates solution file with name from the third argument using the second solution
              = 3 - generates solution file with name from the third argument using the third solution
   - second - name of the input file or the answer file
   - third - name of the file with the solution (the file to be checked or generated)
    */
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include "lunapark_1sol_100p.cpp"
#include "lunapark_2sol_70p.cpp"
#include "lunapark_3sol_30p.cpp"
using namespace std;
int main (int argc, char** argv) {
    FILE *in1,*in2,*out=stdout,*err=stderr;
    int x1,y1,x2,y2;
    if (argc<3) {
       fprintf(out,"-2\n");
       fprintf(err,"The checker needs answer_file and output_file\n");
       return -2;
       }
    in1=fopen(argv[2],"rt");
    if (!in1) {
       fprintf(out,"-1\n");
       fprintf(err,"Could not open answer file!\n");
       return -1;
       }
    if (atoi(argv[1])==1) {
       first_solution(argv[2],argv[3]); return 0;
       }
    if (atoi(argv[1])==2) {
       second_solution(argv[2],argv[3]); return 0;
       }
    if (atoi(argv[1])==3) {
       third_solution(argv[2],argv[3]); return 0;
       }
    in2=fopen(argv[3],"rt");
    if (!in2) {
       fprintf(out,"-1\n");
       fprintf(err,"Could not open output file!\n");
       return -1;
       }
    while (fscanf(in1,"%d",&x1)!=EOF) {
          fscanf(in1,"%d",&y1);
          if (fscanf(in2,"%d",&x2)==EOF) {
             fprintf(out,"0\n");
             fprintf(err,"No answer for some queries!\n");
             return 0;
             }
          if (fscanf(in2,"%d",&y2)==EOF) {
             fprintf(out,"0\n");
             fprintf(err,"No answer for some queries!\n");
             return 0;
             }
          if ((x1!=x2)||(y1!=y2)) {
             fprintf(out,"0\n");
             fprintf(err,"Wrong answer!\n");
             return 0;
             }
          }
    fprintf(out,"1\n");
    fprintf(err,"OK!\n");
    return 0;
}
