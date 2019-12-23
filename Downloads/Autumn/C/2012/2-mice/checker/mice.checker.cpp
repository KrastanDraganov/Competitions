#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;



void print(int cmd) {
     if(cmd == 1) printf("2\nAccepted\n");
     if(cmd == 2) printf("3\nAccepted\n");
     if(cmd == 3) printf("5\nAccepted\n");
     if(cmd == 0) printf("0\nWrong answer\n");
     }


int main(int argc, char *argv[]) {
    string c1_out, c2_out, c1_sol, c2_sol;
    int ans1_out, ans2_out, ans1_sol, ans2_sol;

    //win = fopen(argv[1], "r");
    freopen(argv[2], "r", stdin);
    cin >> c1_out >> ans1_out;
    cin >> c2_out >> ans2_out;
    freopen(argv[3], "r", stdin);
    cin >> c1_sol >> ans1_sol;
    cin >> c2_sol >> ans2_sol;


    int f = 0;

   if((c1_out == c1_sol && ans1_out == ans1_sol) && (c2_out == c2_sol && ans2_out == ans2_sol)) f = 3;
    else if (c1_out == c1_sol && ans1_out == ans1_sol) f = 1;
    else if (c2_out == c2_sol && ans2_out == ans2_sol) f = 2;
    print(f);

   return 0;
   }
