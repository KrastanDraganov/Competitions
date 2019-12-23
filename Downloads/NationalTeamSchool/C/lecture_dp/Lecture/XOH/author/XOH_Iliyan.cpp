#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
long long int matr1[7][7],matr2[7][7],matr3[7][7];
int main () {
    long long int n,mod,i,j,h,ans=0,pow;
    scanf("%lld%lld",&n,&mod);
    if ((mod<1)||(mod>1e9)) cerr << "Error 1!\n";
    if (n<1) cerr << "Error 2!\n";
    else if (n<=30) cerr << "N<=30";
    else if (n<=1e8) cerr << "N<=1e8";
    else if (n>=1e16) cerr << "Error 2!\n";
    matr1[0][0]=matr1[0][5]=matr1[0][6]=1;
    matr1[1][1]=2; matr1[1][2]=1;
    matr1[2][2]=1;
    matr1[3][3]=2;
    matr1[4][4]=2;
    matr1[5][1]=matr1[5][3]=matr1[5][5]=1;
    matr1[6][1]=matr1[6][4]=matr1[6][6]=1;
    for (i=0; i<7; i++) {
        matr2[i][i]=1;
        }
    pow=1;
    for (;;) {
        if (pow>n) break;
        pow*=2;
        }
    pow/=2;
    for (;;) {
        for (i=0; i<7; i++) {
            for (j=0; j<7; j++) {
                matr3[i][j]=matr2[i][j];
                }
            }
        for (i=0; i<7; i++) {
            for (j=0; j<7; j++) {
                matr2[i][j]=0;
                for (h=0; h<7; h++) {
                    matr2[i][j]+=(matr3[i][h]*matr3[h][j])%mod;
                    }
                matr2[i][j]%=mod;
                }
            }
        if ((n&pow)!=0) {
           for (i=0; i<7; i++) {
               for (j=0; j<7; j++) {
                   matr3[i][j]=matr2[i][j];
                   }
               }
           for (i=0; i<7; i++) {
               for (j=0; j<7; j++) {
                   matr2[i][j]=0;
                   for (h=0; h<7; h++) {
                       matr2[i][j]+=(matr3[i][h]*matr1[h][j])%mod;
                       }
                   matr2[i][j]%=mod;
                   }
               }
            }
        pow/=2;
        if (pow==0) break;
        }
    for (i=0; i<7; i++) {
        ans+=matr2[0][i];
        }
    ans%=mod;
    cout << ans ;
    cout << endl ;
    return 0;
}
