/* the checker has three arguments:
   - first - name of the input file
   - second - name of the correct_output file
   - third - name of the contestant_output file
    */
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
char matrix[1001][1001];
int cnt[6][2][1001][1001],sum[2][1001][1001];
char sign[]={'1', '2', '3', '4', '-', '|'};
int main (int argc, char** argv) {
    FILE *in1,*out1,*ans1,*out=stdout,*err=stderr;
    int state,n,m,i,j,h,x,y,num,x1,y1,num1;
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
    fscanf(in1,"%d%d",&n,&m);
    for (i=0; i<n; i++) {
        fscanf(in1,"%s",&matrix[i]);
        }
    for (i=0; i<6; i++) {
        for (j=0; j<n; j++) {
            cnt[i][0][j][0]=0;
            for (h=0; h<m; h++) {
                cnt[i][0][j][h+1]=cnt[i][0][j][h];
                if (matrix[j][h]==sign[i]) cnt[i][0][j][h+1]++;
                }
            }
        for (j=0; j<m; j++) {
            cnt[i][1][0][j]=0;
            for (h=0; h<n; h++) {
                cnt[i][1][h+1][j]=cnt[i][1][h][j];
                if (matrix[h][j]==sign[i]) cnt[i][1][h+1][j]++;
                }
            }
        }
    for (i=0; i<n; i++) {
        sum[0][i][0]=0;
        for (j=0; j<m; j++) {
            sum[0][i][j+1]=sum[0][i][j];
            if (matrix[i][j]!='0') sum[0][i][j+1]++;
            }
        }
    for (i=0; i<m; i++) {
        sum[1][0][i]=0;
        for (j=0; j<n; j++) {
            sum[1][j+1][i]=sum[1][j][i];
            if (matrix[j][i]!='0') sum[1][j+1][i]++;
            }
        }
    for (;;) {
        if (fscanf(ans1,"%d%d%d",&x1,&y1,&num1)==EOF) break;
        if (fscanf(out1,"%d%d%d",&x,&y,&num)==EOF) {
           fprintf(out,"0\n");
           fprintf(err,"Less numbers!\n");
           return 0;
           }
        if ((x!=x1)||(y!=y1)) {
           fprintf(out,"0\n");
           fprintf(err,"Wrong number!\n");
           return 0;
           }
        i=x-1; j=y-1;
        if ((matrix[i][j]!='0')&&(matrix[i][j]!='1')) {
           fprintf(out,"0\n");
           fprintf(err,"Wrong number!\n");
           return 0;
           }
        if ((n-i<num)||(m-j<num)) {
           fprintf(out,"0\n");
           fprintf(err,"Wrong number!\n");
           return 0;
           }
        if (((matrix[i][j+num]!='0')&&(matrix[i][j+num]!='2'))||
            ((matrix[i+num][j]!='0')&&(matrix[i+num][j]!='4'))||
            ((matrix[i+num][j+num]!='0')&&(matrix[i+num][j+num]!='3'))) {
            //cout << i << " " << j << " " << num << " " << matrix[i][j+num] << " " << matrix[i+num][j] << " " << matrix[i+num][j+num] << endl ;
           fprintf(out,"0\n");
           fprintf(err,"Wrong number!\n");
           return 0;
           }
        if (num==1) {
           if ((matrix[i][j]=='0')&&(matrix[i][j+1]=='0')&&(matrix[i+1][j]=='0')&&(matrix[i+1][j+1]=='0')) {
              fprintf(out,"0\n");
              fprintf(err,"Wrong number!\n");
              return 0;
              }
           continue;
           }
        for (h=0; h<4; h++) {
            if ((cnt[h][0][i][j+num]-cnt[h][0][i][j+1]!=0)||
                (cnt[h][1][i+num][j+num]-cnt[h][1][i+1][j+num]!=0)||
                (cnt[h][0][i+num][j+num]-cnt[h][0][i+num][j+1]!=0)||
                (cnt[h][1][i+num][j]-cnt[h][1][i+1][j]!=0)) {
               fprintf(out,"0\n");
               fprintf(err,"Wrong number!\n");
               return 0;
               }
            }
        if ((cnt[5][0][i][j+num]-cnt[5][0][i][j+1]!=0)||
            (cnt[4][1][i+num][j+num]-cnt[4][1][i+1][j+num]!=0)||
            (cnt[5][0][i+num][j+num]-cnt[5][0][i+num][j+1]!=0)||
            (cnt[4][1][i+num][j]-cnt[4][1][i+1][j]!=0)) {
           fprintf(out,"0\n");
           fprintf(err,"Wrong number!\n");
           return 0;
           }
        if ((sum[0][i][j+num+1]-sum[0][i][j]==0)&&
            (sum[1][i+num+1][j+num]-sum[1][i][j+num]==0)&&
            (sum[0][i+num][j+num+1]-sum[0][i+num][j]==0)&&
            (sum[1][i+num+1][j]-sum[1][i][j]==0)) {
           //cout << i << " " << j << " " << num << endl ;
           fprintf(out,"0\n");
           fprintf(err,"Wrong number!\n");
           return 0;
           }
        }
    fprintf(out,"1\n");
    fprintf(err,"OK!\n");
    return 0;
}
