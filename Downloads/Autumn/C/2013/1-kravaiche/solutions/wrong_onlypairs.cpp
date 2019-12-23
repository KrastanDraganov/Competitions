// Finds only answers if they consist of taking only 2 numbers
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c, n;
int a[100100];

int main ()
{
	scanf ("%d%d", &c, &n);
	int i, temp;
	for(i = 1; i <= n; i ++)
	{
		scanf ("%d", &temp);
		temp %= c; 

		if (temp == 0)
		{
			printf("%d\n", i);
			return 0;
		}

		if(a[ c - temp ])
		{
			printf ("%d %d\n", a[c - temp], i);
			return 0;
		}

		a[temp] = i;
	}

	printf("impossible\n");
	return 0;
}