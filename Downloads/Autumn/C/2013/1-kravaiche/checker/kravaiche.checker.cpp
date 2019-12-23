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

int houses[200001];
int used[200001];
int k, n, sum, p;

int main(int argc, char * argv[])
{
    FILE * out = fopen(argv[2],"r");//contestant
    FILE * sol = fopen(argv[3],"r");//judge
	FILE * in = fopen ( argv[1] , "r" );//input

	int i;

	fscanf ( in, "%d %d", &k, &n);

	for (i=1; i<=n; i++) {
	    fscanf ( in, "%d", &houses[i]);
	}

	while (fscanf ( out, "%d", &p) != -1) {
	    if (used[p] == 0) {
	        used[p] = 1;
	        sum += houses[p];
	    } else {
            printf ( "0\nWrong output format\n" );
            return 0;
	    }
	}

	if (!sum) {
        printf ( "0\nWrong output format\n" );
        return 0;
	}

    if (sum%k != 0) {
        printf ( "0\nWrong answer\n" );
        return 0;
    }
    printf ( "%s\nAccepted\n" , argv[4] );
    return 0;
}

