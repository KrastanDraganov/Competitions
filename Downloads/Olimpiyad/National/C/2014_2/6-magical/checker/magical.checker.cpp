#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int used1[100001];
int used2[100001];
int used3[100001];
int used4[100001];
int ans[16], ans_sol[16];
int n, min_sol, max_sol, min_out, max_out, p;

int main(int argc, char * argv[])
{
    FILE * out = fopen(argv[2],"r");//contestant
    FILE * sol = fopen(argv[3],"r");//judge
	FILE * in  = fopen(argv[1],"r");//input

	int i, j;

    fscanf (in, "%d", &n);
    for (i=1; i<=n; i++)
    {
        fscanf ( in, "%d", &p);
        used1[p] = 1;
    }

    fscanf (in, "%d", &n);
    for (i=1; i<=n; i++)
    {
        fscanf ( in, "%d", &p);
        used2[p] = 1;
    }

    fscanf (in, "%d", &n);
    for (i=1; i<=n; i++)
    {
        fscanf ( in, "%d", &p);
        used3[p] = 1;
    }

    fscanf (in, "%d", &n);
    for (i=1; i<=n; i++)
    {
        fscanf ( in, "%d", &p);
        used4[p] = 1;
    }

    int cnt = 0;

	while (fscanf ( out, "%d", &p) != -1)
    {
        ans[cnt++] = p;
        if (cnt > 4) break;
    }

	if (cnt != 4)
    {
        printf ( "0\nWrong output format\n" );
        return 0;
    }

    if (used1[ans[0]] == 0 || used2[ans[1]] == 0 || used3[ans[2]] == 0 || used4[ans[3]] == 0 )
    {
        printf ( "0\nWrong answer\n" );
        return 0;
    }

    min_out = ans[0];
    max_out = ans[0];
    for(i=1; i<4; i++)
    {
        if (ans[i] < min_out) min_out = ans[i];
        if (ans[i] > max_out) max_out = ans[i];
    }

    fscanf ( sol, "%d", &ans_sol[0]);
    min_sol = ans_sol[0];
    max_sol = ans_sol[0];
    for(i=1; i<4; i++)
    {
        fscanf ( sol, "%d", &ans_sol[i]);
        if (ans_sol[i] < min_sol) min_sol = ans_sol[i];
        if (ans_sol[i] > max_sol) max_sol = ans_sol[i];
    }

   /* for (i=0; i<4; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;

     for (i=0; i<4; i++)
    {
        cout << ans_sol[i] << ' ';
    }
    cout << endl;



    cout << max_out - min_out << ' ' << max_sol - min_sol << endl;*/

    if (max_out - min_out != max_sol - min_sol) {
        printf ( "0\nWrong answer\n" );
        return 0;
    }
    printf ( "%s\nAccepted\n" , argv[4] );
    return 0;
}

